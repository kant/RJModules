#include "RJModules.hpp"
#include <iostream>
#include <cmath>
#include <random>

struct Randoms: Module {
    enum ParamIds {
        NUM_PARAMS
    };
    enum InputIds {
        CH1_CV_INPUT_1,
        CH1_CV_INPUT_2,
        CH2_CV_INPUT_1,
        CH2_CV_INPUT_2,
        CH3_CV_INPUT_1,
        CH3_CV_INPUT_2,
        NUM_INPUTS
    };
    enum OutputIds {
        CH1_OUTPUT,
        CH2_OUTPUT,
        CH3_OUTPUT,
        NUM_OUTPUTS
    };

    Randoms() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS) {}
    void step() override;
};

#define ROUND(f) ((float)((f > 0.0) ? floor(f + 0.5) : ceil(f - 0.5)))

void Randoms::step() {
    // float combined_input_1 = params[CH1_PARAM].value * clampf(inputs[CH1_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0);
    // float combined_input_2 = params[CH2_PARAM].value * clampf(inputs[CH2_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0);
    // float combined_input_3 = params[CH3_PARAM].value * clampf(inputs[CH3_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0);

    // // new_value = ( (old_value - old_min) / (old_max - old_min) ) * (new_max - new_min) + new_min
    float mapped_ch1v1 = inputs[CH1_CV_INPUT_1].value;
    float mapped_ch1v2 = inputs[CH1_CV_INPUT_2].value;
    float mapped_ch2v1 = inputs[CH2_CV_INPUT_1].value;
    float mapped_ch2v2 = inputs[CH2_CV_INPUT_2].value;
    float mapped_ch3v1 = inputs[CH3_CV_INPUT_1].value;
    float mapped_ch3v2 = inputs[CH3_CV_INPUT_2].value;

    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator

    if (mapped_ch1v1 == mapped_ch1v2){
        mapped_ch1v1 = -12;
        mapped_ch1v2 = 12;
    }
    std::uniform_real_distribution<> distr1(mapped_ch1v1, mapped_ch1v2); // define the range
    outputs[CH1_OUTPUT].value = distr1(eng);

    if (mapped_ch2v1 == mapped_ch2v2){
        mapped_ch2v1 = -12;
        mapped_ch2v2 = 12;
    }
    std::uniform_real_distribution<> distr2(mapped_ch2v1, mapped_ch2v2); // define the range
    outputs[CH1_OUTPUT].value = distr1(eng);

    if (mapped_ch3v1 == mapped_ch3v2){
        mapped_ch3v1 = -12;
        mapped_ch3v2 = 12;
    }
    std::uniform_real_distribution<> distr3(mapped_ch3v1, mapped_ch3v2); // define the range
    outputs[CH1_OUTPUT].value = distr1(eng);
}

RandomsWidget::RandomsWidget() {
    Randoms *module = new Randoms();
    setModule(module);
    box.size = Vec(15*10, 380);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Randoms.svg")));
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(15, 0)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 0)));
    addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 365)));


    addInput(createInput<PJ301MPort>(Vec(22, 70), module, Randoms::CH1_CV_INPUT_1));
    addInput(createInput<PJ301MPort>(Vec(22, 100), module, Randoms::CH1_CV_INPUT_2));

    addInput(createInput<PJ301MPort>(Vec(22, 150), module, Randoms::CH2_CV_INPUT_1));
    addInput(createInput<PJ301MPort>(Vec(22, 180), module, Randoms::CH2_CV_INPUT_2));

    addInput(createInput<PJ301MPort>(Vec(22, 230), module, Randoms::CH3_CV_INPUT_1));
    addInput(createInput<PJ301MPort>(Vec(22, 260), module, Randoms::CH3_CV_INPUT_2));

    addOutput(createOutput<PJ301MPort>(Vec(110, 85), module, Randoms::CH1_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(110, 165), module, Randoms::CH2_OUTPUT));
    addOutput(createOutput<PJ301MPort>(Vec(110, 245), module, Randoms::CH3_OUTPUT));
}
