<img src="https://i.imgur.com/6W3sCHr.png" width="100%">

# RJModules [![](https://img.shields.io/badge/version-0.5.0-brightgreen.svg)](https://github.com/Miserlou/RJModules/releases) [![](https://img.shields.io/badge/youtube-demo-red.svg)](https://www.youtube.com/watch?v=qkEjmZZbGGo)
Various DIY modules made by Rich Jones for use with [VCV Rack](https://github.com/VCVRack/Rack) 0.6.3 and 1.1.0+.

<!-- START doctoc generated TOC please keep comment here to allow auto update -->
<!-- DON'T EDIT THIS SECTION, INSTEAD RE-RUN doctoc TO UPDATE -->


- [Contents](#contents)
  - [Synths](#synths)
    - [ACID](#acid)
    - [EssEff](#esseff)
  - [Generators](#generators)
    - [Supersaw](#supersaw)
    - [Twin LFO](#twin-lfo)
    - [Noise](#noise)
    - [Range LFO](#range-lfo)
  - [FX](#fx)
    - [Bit Crusher](#bit-crusher)
    - [Filter Delay](#filter-delay)
    - [Sidechain](#sidechain)
    - [Widener](#widener)
    - [Stutter](#stutter)
  - [Filters](#filters)
    - [Filter](#filter)
    - [Filters](#filters-1)
    - [Notch](#notch)
    - [KTF](#ktf)
  - [Numerical](#numerical)
    - [Integers](#integers)
    - [Floats](#floats)
    - [Randoms](#randoms)
  - [Mixers](#mixers)
    - [Left Right Mixer](#left-right-mixer)
    - [Mono](#mono)
    - [Volumes](#volumes)
    - [Panner](#panner)
    - [Panners](#panners)
  - [Musical](#musical)
    - [uQuant](#uquant)
  - [Live](#live)
    - [BPM](#bpm)
    - [Button](#button)
    - [Buttons](#buttons)
    - [Metaknob](#metaknob)
    - [ReplayKnob](#replayknob)
  - [Utilities](#utilities)
    - [Splitter](#splitter)
    - [Splitters](#splitters)
    - [Displays](#displays)
    - [Range](#range)
- [Future Plans](#future-plans)
- [Building](#building)
- [Related Projects](#related-projects)
- [License](#license)

<!-- END doctoc generated TOC please keep comment here to allow auto update -->

## Contents

### Synths

#### ACID
<img src='https://i.imgur.com/zJyg3A9.png' width="50%" />

*"This thing is amaze-balls!! Been messing around with it for about 3 hours didn't even feel the time pass. Acid goodness 👏👏"*

ACID is my take on the legendary TB-303. It features two independent multi-waveform VCOs and mixer, wavetables from the actual 303, an integrated envelope generator, a powerful filter, and a pluck circuit!

Experiment with this and you'll find yourself making some of the craziest, squelchiest acid the world has ever heard!

Oh, and there's also a hidden feature - see if you can find it!


#### EssEff
EssEff is a SoundFont (sf2) player! Comes with a few free soundfonts and the button lets you load more.

### Generators

#### Supersaw
<img src='https://i.imgur.com/ACIUKI0.png' width="25%" />
It's a supersaw! Frequency, detune and mix are all voltage controlled, and there's switches for phase, inversion and 2/3 OSC. There's also a reset button.

#### Twin LFO
<img src="https://i.imgur.com/dsEUqse.png" width="50%" />
Two oscillators, one output! This thing generates crazy wubs - it's super fun! The first LFO is the "main" LFO output, the second one controls the rate of the first. Set the first one higher than the second to get crazy wub effects.

Also has a shape wheel for mixing the sin/saw shape, and has knobs for offset and inversion. All parameters are voltage controllable!

#### Noise
<img src="https://i.imgur.com/l9yj0jt.png" width="25%">
Noise generates pink and white noise! It also has an integreted high pass and low pass filter. Everything is voltage controlled, and there's a bonus volume knob.

#### Range LFO
<img src="https://i.imgur.com/wtTzimg.png" width="50%" />
Range LFO is an LFO which can be explictly mapped to a specific (controllable) range. Very handy!

### FX

#### Bit Crusher
<img src='https://i.imgur.com/tjKYMUn.png' width="50%" />

It's a bit crusher! Accepts control voltage, and sets a (voltage controlled) minimum bit depth for fine tuning.

#### Filter Delay
<img src="https://i.imgur.com/9CPtg6R.png" width="25%" />
A modification of the basic delay that filters each feedbacking pass. Kind of reggaeish, good for pads too.

#### Sidechain
<img src="https://i.imgur.com/3bQONmT.png" width="25%">
Based on a trigger signal, lower the volume of the input/output signal. CV controllable decay and ratio. Use a kick or a button to make some awesome wooshy noises or hard-knocking beats! I think there's a bug in this module but it works pretty good for me anyway.

#### Widener
<img src="https://i.imgur.com/KL50fgV.png" width="25%" />
Widener is a CV-controlled Haas-effect stereo widener with integrated high pass/low pass filter and a mix knob. Really useful for adding motion to a lead or for making drums rumble!

#### Stutter
<img src="https://i.imgur.com/oHHdCHF.png" width="25%" />
It's a digital glitch effect! Use the main on/off button (and related input) to turn the looper on and off, then use the time knob (controllable with CV) to adjust the size of the stutter. Also has a mix knob.

### Filters

#### Filter
<img src="https://i.imgur.com/xv2GyWO.png" width="25%">
Filter is a voltage-controlled integrated high-pass and low-pass filter. Also includes a voltage-controlled res and mix paramater knobs. It's a really good VCF.

#### Filters
<img src="https://i.imgur.com/ApBCVaC.png" width="25%">
Filters is like Volumes or Panners, but for Filters. Each knob controls both a low pass and high pass filter. Super handy!

#### Notch
<img src="https://i.imgur.com/AzhKPZ1.png" width="25%">
Notch is a notch filter! You can play with the frequency, depth and width. All voltage controlled.

#### KTF
<img src="https://i.imgur.com/TAHjvkB.png" width="25%">
KTF is a key-tracking filter - a filter that takes a V/OCT pitch input. So, the peak of the filter will match your note. Includes an integrated octave and glide. Sounds pretty cool on saws!

### Numerical

#### Integers
<img src='https://i.imgur.com/NRQjpmZ.png' width="25%" />
It generates three (voltage controlled) integers from -12 to +12!

#### Floats
<img src='https://i.imgur.com/spQgKmr.png' width="25%" />
It generates three (voltage controlled) floats from -12 to +12!

#### Randoms
<img src='https://i.imgur.com/CuM471K.png' width="50%" />

Generates three random values. The range of the values can be controlled via CV, but will default to (-12, +12) if CV values are empty/equal.

### Mixers

#### Left Right Mixer
<img src="https://i.imgur.com/UOidGVr.png" width="25%" />
A simple 12-to-2 mixer for mixing multiple stereo signals. With an additional overall voume knob.

#### Mono
<img src="https://i.imgur.com/tmSFepy.png" width="25%" />
A voltage-controlled mono-izer. Given a wide dual input signal, convert to mono outputs based on a knob and CV. Has two outputs, but only one is need if you're just going to 100% mono.

#### Volumes
<img src="https://i.imgur.com/KqWUEvB.png" width="25%" />
A modification of 'Mutes' that adds the ability to adjust the volume of 10 different input-output pairs. Can be used to quiet and amplify.

#### Panner
<img src="https://i.imgur.com/4z5li8u.png" width="25%" />
Panner is a voltage controlled panner. Without CV, it pans a mono signal into left and right channels based on the value of the knob. Combine with an LFO to build an autopanner!

#### Panners
<img src="https://i.imgur.com/Z53pj0S.png" width="25%" />
Panners is a bank of 5 panners. Each takes a stereo input and a stereo output. Pretty simple but handy for placing lots of elements around a stereo space.

### Musical

#### uQuant
<img src='https://i.imgur.com/E2mbiRr.png' width="5%">

uQuant is a very skinny micro quantizer. Includes key, scale, octave, transpose, trigger and output.

uQuant is really just a bastard skin of [Scale Quantizer mkII](https://github.com/jhoar/AmalgamatedHarmonics) by [AmalgamatedHarmonics](https://github.com/jhoar/AmalgamatedHarmonics) - so all credit goes to them!

### Live

#### BPM
<img src='https://i.imgur.com/A5MbJJq.png' width="25%">
BPM lets you set a voltage-controllable beats per minute, with an array of outputs that get a +12 signal. There is also a CV reset with a connected button.

You can get some weird polyrhythmic stuff by putting an LFO on the CV, which gives a variable BPM. Even weirder if you start using a bunch!

#### Button
<img src='https://i.imgur.com/msNcs07.png' width="25%" />
It's literally just a big ass button with six outputs. You hit it, it sends a +12 reset signal.

#### Buttons
<img src='https://i.imgur.com/A3SD0WT.png' width="25%" />
It's not one big button - it's lot of little butons!

They're arranged a drum pad, so it's fun and easy to make a playable drum pad simulator by building a circuit like this:

<img src='https://i.imgur.com/qdBbvFD.jpg' width="100%" />

#### Metaknob
<img src="https://i.imgur.com/S7caSTN.png" width="25%" />
It's a really big knob! Unipolar, bipolar and range-controlled modes.

[Demo here](https://www.youtube.com/watch?v=hWrgh6OjMlU)!

#### ReplayKnob
<img src="https://i.imgur.com/5z6xiwB.png" width="25%" />
Replay Knob is a knob with an integratd recorder and looper. Has a reset button, start/end controls, comes in unipolar and bipolar modes, and can be used as a looper for arbitrary inputs. Great for looping human-sounding controls.

### Utilities

#### Splitter
<img src="https://i.imgur.com/bvJKVEn.png" width="25%" />
It's a 1 to 9-way splitter! You've got a signal - now send it everywhere!

#### Splitters
<img src="https://i.imgur.com/NVWwfnZ.png" width="25%" />
If splitting one signal to many isn't your fancy, Splitters gives you a 5:10 splitter instead! Handy!

#### Displays
<img src="https://i.imgur.com/JVVs2fg.png" width="25%">
Three digital displays. Useful for debugging. Provides a passthrough output as well.

#### Range
<img src="https://i.imgur.com/3EgRCQ6.png" width="50%" />
Range will map an input from one range of values to another. So, if you have an oscillator which outputs from 0/2, you can map it to a -5/5 audio signal or a -10/10 CV. Handy!


## Future Plans

None of them actually exist yet, but I'm hoping this will project eventually contain:

  * FFTTuner - FFT / Tuner
  * ~VCDryWet - A simple dry/wet mixer~
  * DubEcho - Two delays and a spring.
  * ~Ping Pong Delay (or maybe just a delay with seperate dry/wet outs that can feed to the panner?)~
  * Vocoder, maybe?
  * Dedicated 808/kick circuit with click
  * Reverb - It's a reverb!
  * Phaser - Pssshheeeeeooooooowwwwwwoooowowwaaaaaahhhhhh
  * Harmonic Saturator
  * Ring Modulator
  * Granulator
  * Shepard Tone Generator
  * BPM LFO - LFO with integrated divisible BPM (including triplets), for triplet wubs
  * Wobbler - Selectable classic wobble automation shapes
  * 3xOSC - The classic, RJ style
  * MIDI Recorder - record MIDI notes to a MIDI file
  * Wubber - Integrated LCA + LFO with adjustable pulse width and clock divider
  * ~Memory - Record a signal to a buffer, loop/trigger it back. Integrated knob. 4 banks.~
  * XYFX - Kaos Pad-inspired multi-FX rack.
  * OscPhrase - Phrase generation based on a slow LFO
  * LFOArp - Arp with LFO for controlling speed
  * Band Splitter - Split into L/M/H bands
  * Cycle Gate - Only allow through a controlable number of cycles. Ex, if set to 3, allows 3 cycles of wave (until a value repeats) until the signal is gated.
  * Keyboard Keyboard - Keyboard that allows you to send CV with the computer keyboard in the same configuration as the one in Ableton.
  * Kielbasa Thickener - Sausage Fattener clone
  * Divide Delay - Delay with an integrated clock divider. Also has an integrated send/return for the wet signal.
  * Mixixix - 4 channel mixer with send/return chains and integrated sidechain.
  * Shitty - Makes a signal sound shitty. Lofi. So hot right now.
  * Loop Station - 8 track loop station clone. Integrated Trim.
  * The Beast - Chord, Arp, 3xLFO+Filter, Sync, ADSR, VCO, Quantizer, Keyboard, Master Out. All in one panel.
  * Feedback - Self-feeding reverb. Size, decay, damp, mix, drive, bypass.
  * DJ Suite: Player, Mixer, Library
  * 42VCO: 4xOSC -> 2 Mix -> 1 Mix
  * Drumpler!
  * Reese! (2 saws with independent LFP, mixed into a notch filter and overdrive before final LPF)
  * ~VOCTFILT - Filter where the cutoff maps to v/oct~
  * That Fucking Wub - That fucking FM wubber!
  * Pedalboard - Send/return bypass buttons for various effects, to simulate the utility of a guitar's pedalboard. Maybe add dry wets for fun.
  * Fretboard - 'Quantum' for people who play the guitar, not the piano..
  * Counters - 4x counters that trigger in/out (for structuring tracks)
  * PaulStretch/PADSynth
  * ~[SeqUFD](https://cavisynth.com/product/seq-ufd/) clone~
  * ~Trigger Switch~
  * Ghetto Pog - Bootleg of EHX POG module
  * ~Playable Chord - turn a note into a chord!~
  * ~Brick Wall Limiter~
  * Multi-Tap Delay (lol that super expensive digital one) - dry//75/150/225/300/375/450/525/600 + [.1x:2x] modifier, individual outputs + mixed, pingpong, odd/even outs, feedback
  * Slapback Delay

## Building

Steps since 0.6.0 (Mac):
   * Download and install Rack to Applications
   * Download the Rack SDK
   * Clone this repo
   * `RACK_DIR=~/Downloads/Rack-SDK/ make dist`
   * `mkdir -p /Applications/Rack.app/Contents/Resources/plugins`
   * `copy -r dist RJModules /Applications/Rack.app/Contents/Resources/RJModules`
   * `/Applications/Rack.app/Contents/MacOS/Rack -d`


## Related Projects

  * [Autopan](https://github.com/Miserlou/Autopan)

## License

(c) Rich Jones 2017, BSD.
