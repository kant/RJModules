#include "RJModules.hpp"
#include <iostream>
#include "dsp/digital.hpp"

#define NUM_PARAMSS 5
#define NUM_CHANNELS 10

struct Panners : Module {
    enum ParamIds {
        MUTE_PARAM,
        NUM_PARAMS = MUTE_PARAM + NUM_PARAMSS
    };
    enum InputIds {
        IN_INPUT,
        NUM_INPUTS = IN_INPUT + NUM_CHANNELS
    };
    enum OutputIds {
        OUT_OUTPUT,
        NUM_OUTPUTS = OUT_OUTPUT + NUM_CHANNELS
    };
    enum LightIds {
        MUTE_LIGHT,
        NUM_LIGHTS = MUTE_LIGHT + NUM_CHANNELS
    };

    bool state[NUM_CHANNELS];
    SchmittTrigger muteTrigger[NUM_CHANNELS];

    Panners() {
		config(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS, NUM_LIGHTS);
        configParam(Panners::MUTE_PARAM + 0, 0.0, 1.0, 0.5, "");
        configParam(Panners::MUTE_PARAM + 1, 0.0, 1.0, 0.5, "");
        configParam(Panners::MUTE_PARAM + 2, 0.0, 1.0, 0.5, "");
        configParam(Panners::MUTE_PARAM + 3, 0.0, 1.0, 0.5, "");
        configParam(Panners::MUTE_PARAM + 4, 0.0, 1.0, 0.5, "");
    }
    void step() override;

    json_t *dataToJson() override {
        json_t *rootJ = json_object();
        // states
        json_t *statesJ = json_array();
        for (int i = 0; i < NUM_CHANNELS; i++) {
            json_t *stateJ = json_boolean(state[i]);
            json_array_append_new(statesJ, stateJ);
        }
        json_object_set_new(rootJ, "states", statesJ);
        return rootJ;
    }
    void dataFromJson(json_t *rootJ) override {
        // states
        json_t *statesJ = json_object_get(rootJ, "states");
        if (statesJ) {
            for (int i = 0; i < NUM_CHANNELS; i++) {
                json_t *stateJ = json_array_get(statesJ, i);
                if (stateJ)
                    state[i] = json_boolean_value(stateJ);
            }
        }
    }
};

void Panners::step() {

    float in;
    float in2;
    float remapped;

    for (int i = 0; i < NUM_PARAMSS; i++) {

        in = inputs[IN_INPUT + 2*i].value;
        in2 = inputs[IN_INPUT + 2*i + 1].value;

        remapped = 1;

        //pan right
        if(params[MUTE_PARAM + i].value > .5){

            // new_value = ( (old_value - old_min) / (old_max - old_min) ) * (new_max - new_min) + new_min
            remapped = ( (params[MUTE_PARAM + i].value - 0.5) / (1.0 - 0.5) ) * (1.0 - 0) + 0;
            outputs[OUT_OUTPUT + 2*i].value = in * (1 - remapped);

            // Right is the same
            outputs[OUT_OUTPUT + 2*i + 1].value = in2;

        //pan left
        } else if (params[MUTE_PARAM + i].value < .5){

            // Left is the same
            outputs[OUT_OUTPUT + 2*i].value = in;

            // new_value = ( (old_value - old_min) / (old_max - old_min) ) * (new_max - new_min) + new_min
            remapped = params[MUTE_PARAM + i].value / .5;
            outputs[OUT_OUTPUT + 2*i + 1].value = in2 * remapped;

        //center
        } else{

            outputs[OUT_OUTPUT + 2*i].value = in;
            outputs[OUT_OUTPUT + 2*i + 1].value = in2;
        }

    }
}


template <typename BASE>
struct MuteLight : BASE {
    MuteLight() {
        this->box.size = mm2px(Vec(6.0, 6.0));
    }
};

struct PannersWidget: ModuleWidget {
    PannersWidget(Panners *module);
};

PannersWidget::PannersWidget(Panners *module) {
		setModule(module);
    setPanel(SVG::load(assetPlugin(pluginInstance, "res/Panners.svg")));

    addChild(createWidget<ScrewSilver>(Vec(15, 0)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 30, 0)));
    addChild(createWidget<ScrewSilver>(Vec(15, 365)));
    addChild(createWidget<ScrewSilver>(Vec(box.size.x - 30, 365)));

    addParam(createParam<RoundSmallBlackKnob>(mm2px(Vec(15.57, 23.165)), module, Panners::MUTE_PARAM + 0));
    addParam(createParam<RoundSmallBlackKnob>(mm2px(Vec(15.57, 43.164)), module, Panners::MUTE_PARAM + 1));
    addParam(createParam<RoundSmallBlackKnob>(mm2px(Vec(15.57, 63.164)), module, Panners::MUTE_PARAM + 2));
    addParam(createParam<RoundSmallBlackKnob>(mm2px(Vec(15.57, 83.165)), module, Panners::MUTE_PARAM + 3));
    addParam(createParam<RoundSmallBlackKnob>(mm2px(Vec(15.57, 103.164)), module, Panners::MUTE_PARAM + 4));

    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 17.81)), PortWidget::INPUT, module, Panners::IN_INPUT + 0));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 27.809)), PortWidget::INPUT, module, Panners::IN_INPUT + 1));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 37.809)), PortWidget::INPUT, module, Panners::IN_INPUT + 2));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 47.81)), PortWidget::INPUT, module, Panners::IN_INPUT + 3));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 57.81)), PortWidget::INPUT, module, Panners::IN_INPUT + 4));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 67.809)), PortWidget::INPUT, module, Panners::IN_INPUT + 5));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 77.81)), PortWidget::INPUT, module, Panners::IN_INPUT + 6));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 87.81)), PortWidget::INPUT, module, Panners::IN_INPUT + 7));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 97.809)), PortWidget::INPUT, module, Panners::IN_INPUT + 8));
    addInput(createPort<PJ301MPort>(mm2px(Vec(4.214, 107.809)), PortWidget::INPUT, module, Panners::IN_INPUT + 9));

    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 17.81)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 0));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 27.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 1));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 37.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 2));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 47.81)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 3));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 57.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 4));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 67.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 5));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 77.81)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 6));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 87.81)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 7));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 97.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 8));
    addOutput(createPort<PJ301MPort>(mm2px(Vec(28.214, 107.809)), PortWidget::OUTPUT, module, Panners::OUT_OUTPUT + 9));
}

Model *modelPanners = createModel<Panners, PannersWidget>("Panners");
