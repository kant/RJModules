#include "RJModules.hpp"
#include <iostream>
#include <cmath>
#include <random>
#include "VAStateVariableFilter.h"

struct Notch: Module {
    enum ParamIds {
        FREQ_PARAM,
        VOL_PARAM,
        WIDTH_PARAM,
        NUM_PARAMS
    };
    enum InputIds {
        CH1_INPUT,
        FREQ_CV_INPUT,
        VOL_CV_INPUT,
        WIDTH_CV_INPUT,
        NUM_INPUTS
    };
    enum OutputIds {
        CH1_OUTPUT,
        NUM_OUTPUTS
    };

    VAStateVariableFilter *notchFilter = new VAStateVariableFilter() ; // create a hpFilter;


    Notch() : Module(NUM_PARAMS, NUM_INPUTS, NUM_OUTPUTS) {}
    void step() override;
};

void Notch::step() {

    float dry = inputs[CH1_INPUT].value;
    float wet = 0.0;

    dry += 1.0e-6 * (2.0*randomf() - 1.0)*1000;

    notchFilter->setFilterType(5);

    notchFilter->setCutoffFreq(params[FREQ_PARAM].value *  clampf(inputs[FREQ_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0));
    notchFilter->setShelfGain(params[VOL_PARAM].value *  clampf(inputs[VOL_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0));
    notchFilter->setResonance(params[WIDTH_PARAM].value*  clampf(inputs[WIDTH_CV_INPUT].normalize(10.0) / 10.0, 0.0, 1.0));
    notchFilter->setSampleRate(engineGetSampleRate());

    wet = notchFilter->processAudioSample(dry, 1);
    outputs[CH1_OUTPUT].value = wet;
}


NotchWidget::NotchWidget() {
    Notch *module = new Notch();
    setModule(module);
    box.size = Vec(15*10, 380);

    {
        SVGPanel *panel = new SVGPanel();
        panel->box.size = box.size;
        panel->setBackground(SVG::load(assetPlugin(plugin, "res/Notch.svg")));
        addChild(panel);
    }

    addChild(createScrew<ScrewSilver>(Vec(15, 0)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 0)));
    addChild(createScrew<ScrewSilver>(Vec(15, 365)));
    addChild(createScrew<ScrewSilver>(Vec(box.size.x-30, 365)));

    addParam(createParam<RoundHugeBlackKnob>(Vec(47, 61), module, Notch::FREQ_PARAM, 30.0, 6000.0, 1000.0));
    addParam(createParam<RoundHugeBlackKnob>(Vec(47, 143), module, Notch::VOL_PARAM,  0.0, 5.0, 2));
    addParam(createParam<RoundHugeBlackKnob>(Vec(47, 228), module, Notch::WIDTH_PARAM, 0.0, 1.0, 0.5));

    addInput(createInput<PJ301MPort>(Vec(22, 100), module, Notch::FREQ_CV_INPUT));
    addInput(createInput<PJ301MPort>(Vec(22, 180), module, Notch::VOL_CV_INPUT));
    addInput(createInput<PJ301MPort>(Vec(22, 260), module, Notch::WIDTH_CV_INPUT));
    addInput(createInput<PJ301MPort>(Vec(22, 310), module, Notch::CH1_INPUT));

    addOutput(createOutput<PJ301MPort>(Vec(110, 310), module, Notch::CH1_OUTPUT));
}
