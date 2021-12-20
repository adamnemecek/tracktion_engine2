/*
    ,--.                     ,--.     ,--.  ,--.
  ,-'  '-.,--.--.,--,--.,---.|  |,-.,-'  '-.`--' ,---. ,--,--,      Copyright 2018
  '-.  .-'|  .--' ,-.  | .--'|     /'-.  .-',--.| .-. ||      \   Tracktion Software
    |  |  |  |  \ '-'  \ `--.|  \  \  |  |  |  |' '-' '|  ||  |       Corporation
    `---' `--'   `--`--'`---'`--'`--' `---' `--' `---' `--''--'    www.tracktion.com

    Tracktion Engine uses a GPL/commercial licence - see LICENCE.md for details.
*/

#pragma once

#if TRACKTION_BENCHMARKS

#include "tracktion_BenchmarkUtilities.h"


namespace tracktion_engine
{

using namespace tracktion_graph;

//==============================================================================
//==============================================================================
class RackBenchmarks : public juce::UnitTest
{
public:
    RackBenchmarks()
        : juce::UnitTest ("Rack Benchmarks", "tracktion_benchmarks")
    {
    }
    
    void runTest() override
    {
        using namespace benchmark_utilities;
        using namespace tracktion_graph;
        test_utilities::TestSetup ts;
        ts.sampleRate = 96000.0;
        ts.blockSize = 128;

        auto& engine = *tracktion_engine::Engine::getEngines()[0];

        runRackMixBusTest (engine, ts);
    }
    
    void runRackMixBusTest (Engine& engine, test_utilities::TestSetup ts)
    {
        using namespace benchmark_utilities;
        using namespace tracktion_graph;
        
        static constexpr unsigned char RackMixBus_zip[] =
        { 120,156,237,157,207,115,220,70,118,199,135,146,70,178,189,187,149,181,55,169,178,47,217,57,165,188,135,213,162,127,162,145,67,74,20,73,123,89,22,127,132,164,180,155,75,92,35,114,36,77,76,114,88,195,161,108,237,41,247,61,228,156,115,170,146,75,170,82,
        251,39,236,63,144,63,98,255,133,252,3,105,204,47,14,56,141,158,238,198,107,160,199,108,86,89,38,103,128,7,60,244,123,15,141,47,240,193,219,217,222,61,105,109,180,187,87,87,175,122,195,235,254,224,178,181,241,89,251,119,221,247,189,55,131,225,69,7,161,
        167,248,41,74,90,87,195,193,191,244,78,71,187,219,173,141,159,183,105,210,235,98,252,27,212,21,189,94,218,109,157,14,123,221,145,92,241,164,127,209,107,109,252,85,27,241,68,16,156,114,150,50,129,90,231,221,235,209,113,255,237,101,255,77,255,180,123,57,
        218,122,215,189,124,43,23,251,89,27,165,252,181,120,131,123,25,65,173,139,193,153,252,190,119,246,252,67,110,96,187,251,190,127,214,57,26,124,127,222,189,60,107,109,252,237,201,209,230,254,241,225,193,145,220,207,135,189,203,179,147,193,78,254,241,198,
        195,235,211,225,205,235,221,203,81,111,248,190,123,222,218,248,235,118,242,52,165,201,226,15,105,93,13,174,251,163,177,87,109,249,117,210,106,237,109,110,29,29,28,110,30,109,238,237,156,236,28,29,75,59,125,105,236,113,27,37,9,106,181,78,118,246,14,15,
        142,119,254,241,229,206,254,214,78,171,181,241,96,252,129,220,238,245,168,59,28,61,151,142,206,12,189,190,186,104,109,60,105,35,156,255,113,122,51,124,223,203,191,65,249,38,78,118,247,118,142,119,191,150,107,93,222,92,244,134,221,209,96,40,127,111,211,
        214,89,239,114,112,209,191,188,253,96,201,106,235,112,247,100,235,183,11,59,176,49,254,64,238,200,210,162,87,253,209,233,187,214,198,163,54,151,171,189,218,221,222,57,104,181,90,155,47,79,14,246,54,15,127,191,247,66,254,177,245,98,119,235,27,121,240,
        182,190,145,118,206,123,239,123,242,32,253,66,174,139,178,140,97,142,9,163,28,201,127,91,173,221,109,242,234,224,232,249,238,177,60,38,155,219,155,39,155,114,123,163,97,247,244,187,253,155,139,215,189,241,190,162,214,89,119,212,203,15,20,78,240,248,48,
        30,203,195,247,234,224,197,203,189,201,110,190,120,249,245,238,190,220,157,209,135,43,185,216,71,237,247,131,115,233,124,107,250,191,241,224,112,146,114,44,16,17,9,103,132,200,216,152,31,121,210,234,93,118,95,159,247,206,38,155,218,120,160,25,37,185,
        191,123,7,219,187,95,237,238,28,109,30,203,195,188,191,183,179,127,114,44,221,205,29,149,255,223,248,104,226,241,195,217,26,114,119,47,187,23,227,152,123,126,115,253,247,168,243,67,71,252,90,250,211,31,142,62,76,183,247,114,105,123,15,230,107,147,197,
        37,91,191,219,221,223,62,248,221,241,201,230,201,142,116,246,251,254,229,217,224,251,195,193,117,158,22,88,116,228,238,117,152,252,47,37,105,171,123,58,234,231,65,241,176,157,180,38,203,189,24,156,126,55,115,113,209,230,193,203,147,195,151,50,184,31,
        204,118,243,162,127,214,239,12,110,70,87,55,35,221,130,159,182,39,203,116,80,231,203,243,222,155,209,175,116,11,127,54,91,24,119,190,28,246,223,190,211,47,253,113,251,229,101,254,219,89,92,40,46,228,178,208,238,254,226,50,63,157,132,116,255,242,110,68,
        23,23,251,121,123,188,132,58,158,139,139,126,58,93,84,29,205,179,2,145,23,142,197,207,191,218,220,218,57,124,49,206,221,39,223,247,207,70,178,126,126,209,198,244,105,162,248,105,189,235,229,134,91,27,159,183,185,122,129,238,205,104,112,220,255,67,111,
        41,163,187,215,215,242,140,183,115,91,210,18,89,233,135,189,113,189,206,191,191,254,174,127,153,87,151,253,193,80,126,253,197,115,89,175,190,62,58,120,185,191,157,215,157,139,238,219,222,230,249,213,187,110,190,101,164,222,242,162,79,47,54,159,239,188,
        144,191,191,30,220,92,158,201,66,244,73,27,145,78,214,33,29,220,26,245,126,24,229,39,41,89,246,58,108,197,74,24,43,86,18,171,182,196,21,43,241,85,43,101,138,149,210,194,74,199,47,228,249,236,72,22,216,217,90,31,183,145,92,133,72,219,215,163,15,231,227,
        80,57,239,95,246,186,67,57,105,25,201,137,197,121,235,170,59,148,129,33,231,2,187,219,215,249,233,230,234,252,230,109,255,242,91,89,192,233,183,211,147,208,202,45,160,241,110,77,183,240,217,116,11,191,29,12,251,127,24,92,142,150,182,241,105,97,27,87,
        221,203,85,27,160,206,46,8,67,23,104,5,23,132,137,11,169,171,11,4,27,186,144,186,187,32,183,177,210,5,25,126,137,179,15,220,200,135,241,38,220,157,224,70,78,16,103,39,50,83,39,72,5,39,50,35,39,184,171,19,212,44,154,198,155,112,118,130,154,133,83,230,
        236,132,113,56,101,21,156,48,10,39,89,252,29,157,96,137,161,19,114,19,206,78,200,141,220,117,226,238,105,37,47,223,203,103,21,180,98,29,170,88,7,175,88,39,85,172,67,86,157,242,18,197,74,180,176,210,228,2,106,119,95,94,90,228,87,126,27,143,126,200,207,
        255,242,98,141,210,148,112,65,177,60,12,152,19,36,47,162,104,235,195,228,187,85,115,3,121,173,217,191,232,95,207,47,171,230,87,105,143,231,87,55,180,117,231,130,173,112,33,54,187,122,51,217,88,62,66,229,11,110,60,212,92,98,113,229,228,109,241,234,174,
        116,26,247,209,116,26,247,121,91,172,154,197,17,208,89,156,188,232,239,94,190,239,94,79,86,253,89,59,233,36,29,156,38,29,154,38,119,230,119,143,85,177,42,131,65,70,231,36,28,62,106,191,50,58,53,230,5,89,38,170,97,146,206,71,84,31,206,76,154,188,221,149,
        118,251,208,100,18,48,89,197,52,147,219,237,187,217,11,50,227,109,23,167,110,183,78,204,114,191,48,90,147,49,121,208,174,156,116,136,98,154,45,252,136,52,205,140,146,238,201,60,222,133,54,233,38,23,56,127,51,13,138,206,223,117,228,144,116,14,199,181,
        176,174,132,204,98,66,2,164,78,29,81,142,13,162,220,79,41,241,82,24,202,19,146,16,129,9,195,25,69,40,229,148,39,50,233,166,9,137,5,37,136,164,152,209,44,65,25,79,120,202,152,93,66,18,28,120,66,18,18,19,178,241,132,244,122,70,94,145,230,196,45,205,189,
        38,100,38,103,143,243,127,136,204,204,89,66,82,121,202,36,25,22,44,149,231,74,193,120,38,19,212,50,33,121,232,9,153,198,132,108,60,33,205,82,135,222,151,51,36,39,116,225,31,146,178,121,66,202,20,100,34,191,247,38,56,203,210,140,48,94,188,228,50,72,200,
        44,240,132,164,40,38,228,154,36,36,187,47,9,89,126,13,153,34,38,211,17,167,242,204,137,68,34,82,121,17,105,121,134,164,161,79,89,41,139,9,185,38,9,201,99,66,202,185,42,91,60,138,36,203,82,203,132,12,125,202,74,163,168,179,46,9,153,222,151,132,68,44,201,
        168,188,86,148,231,66,46,231,173,41,22,147,132,92,125,36,87,39,36,75,2,79,72,134,99,66,54,158,144,107,148,70,102,181,67,24,212,142,173,131,253,253,157,173,147,221,3,153,47,237,235,225,233,100,209,179,235,209,252,166,160,252,240,48,95,113,250,249,237,
        239,142,86,208,130,21,228,108,5,47,88,193,86,86,4,136,71,2,196,35,1,225,17,193,16,30,21,172,56,123,84,176,226,238,17,7,241,136,131,120,196,65,60,202,64,60,202,64,60,202,32,60,162,32,81,71,65,162,142,130,68,29,5,137,58,10,18,117,20,36,234,228,188,7,192,
        163,130,21,103,143,10,86,108,60,154,22,202,177,161,241,105,204,201,163,233,9,4,194,138,114,95,22,61,226,206,86,22,143,46,115,246,104,113,95,168,179,149,197,125,33,6,86,8,134,56,186,106,43,139,251,146,58,91,89,60,46,194,52,118,203,119,100,85,248,79,207,
        30,16,7,69,105,101,113,95,50,103,43,183,7,229,145,92,198,196,76,6,226,146,210,10,90,220,25,227,242,82,62,202,38,181,69,189,39,133,195,98,98,134,130,132,191,218,74,225,176,152,228,162,218,76,193,39,147,194,64,65,162,87,109,165,176,51,38,21,83,109,166,
        112,104,76,74,38,83,6,141,173,79,106,43,133,157,49,169,83,106,51,133,67,83,44,84,5,230,236,241,2,115,246,105,155,161,180,131,112,210,225,57,120,38,13,223,66,103,72,15,157,77,164,145,252,183,235,81,247,244,187,87,253,222,247,135,195,193,213,96,152,195,
        146,255,164,81,52,90,119,232,186,20,41,232,186,66,238,232,232,186,20,151,123,26,233,186,184,80,92,40,210,117,119,51,58,210,117,218,149,28,233,58,103,56,35,101,94,217,183,180,6,246,45,245,203,190,9,228,159,125,147,219,240,202,190,9,86,3,251,38,12,66,169,
        10,251,38,234,96,223,132,103,246,45,35,53,176,111,114,35,94,217,183,44,53,199,198,220,54,129,18,101,214,253,232,184,49,72,84,58,53,77,242,10,48,95,62,46,102,161,229,30,188,233,210,22,154,161,235,82,22,0,93,151,70,186,46,210,117,247,136,174,75,67,167,
        235,68,18,19,178,241,231,62,34,93,87,27,93,39,80,232,9,73,99,66,54,158,144,145,174,171,141,174,19,250,105,105,0,9,41,98,66,54,158,144,145,174,171,141,174,19,161,211,117,89,164,235,214,37,33,35,93,7,64,215,101,36,244,132,140,83,214,117,73,200,72,215,1,
        208,117,114,249,192,19,50,78,89,215,37,33,239,13,93,87,158,144,89,70,72,66,166,87,144,41,34,25,23,118,162,14,74,2,23,117,80,18,233,186,230,19,114,141,210,168,54,186,46,101,16,124,70,193,138,51,159,81,176,226,76,156,164,32,116,93,10,66,215,165,32,116,
        157,64,16,30,21,172,56,123,84,176,226,238,17,72,212,9,144,168,19,32,81,39,64,232,58,1,66,215,9,16,186,78,94,117,2,120,84,176,226,236,81,193,138,187,71,41,136,71,41,136,71,41,128,71,249,188,167,186,71,69,43,174,30,21,173,216,18,48,41,8,93,39,79,32,16,
        86,64,232,58,181,21,91,186,78,237,145,45,93,167,182,98,75,215,9,4,113,116,213,86,108,233,58,181,149,6,232,58,1,18,114,106,43,182,116,157,218,138,53,93,39,64,232,58,181,149,38,232,58,245,158,88,211,117,242,28,4,112,88,212,86,172,233,58,181,25,107,186,
        46,23,190,0,124,82,90,177,166,235,212,102,108,233,186,252,60,84,221,167,18,43,182,116,93,137,25,55,186,142,98,222,65,136,52,71,215,33,101,239,186,66,184,106,232,58,132,35,93,23,23,138,11,217,46,20,233,186,72,215,149,173,84,107,239,58,84,67,239,58,228,
        183,119,29,194,102,164,79,21,126,47,223,134,71,126,15,17,179,30,87,85,248,189,124,27,62,249,61,100,216,127,175,18,191,135,12,27,240,185,242,123,136,152,165,67,37,126,47,223,136,79,126,15,153,119,17,116,231,247,144,89,23,65,119,184,142,214,208,246,45,
        223,200,143,190,237,27,36,85,137,136,25,43,93,137,174,203,55,18,4,93,135,66,232,93,135,112,124,205,121,164,235,238,15,93,39,167,90,129,63,247,17,123,215,5,240,220,71,164,235,234,162,235,228,133,67,224,9,73,34,59,208,124,66,70,186,174,46,186,14,133,222,
        76,18,197,102,146,1,36,100,164,235,234,162,235,16,209,95,39,6,144,144,241,26,114,93,18,50,210,117,213,233,58,20,122,119,87,20,187,187,174,77,66,70,186,238,169,144,23,143,249,123,152,39,44,15,37,137,76,80,203,132,12,252,149,73,136,68,81,103,93,18,242,
        222,208,117,30,123,215,33,26,186,168,19,219,45,7,144,144,107,148,70,117,209,117,8,164,119,29,2,233,93,135,64,122,215,229,119,92,32,60,130,96,104,138,86,156,61,34,16,29,170,138,86,156,61,42,88,113,247,8,162,47,26,2,233,198,135,64,186,241,229,162,9,132,
        71,32,121,68,64,242,8,164,191,32,2,233,47,136,64,250,11,230,211,118,8,143,32,184,219,162,21,103,143,40,72,101,160,32,149,129,186,86,134,105,161,4,64,34,64,122,215,149,236,139,37,93,87,98,197,146,174,43,241,200,146,174,43,177,98,73,215,229,165,31,224,
        232,170,173,88,210,117,37,86,234,167,235,16,72,67,191,18,43,150,116,93,137,21,91,186,46,63,125,64,184,180,34,230,106,163,235,74,246,196,150,174,67,32,93,10,75,172,216,210,117,37,102,108,233,186,252,44,4,225,211,10,28,217,140,174,43,49,99,77,215,81,144,
        50,165,182,98,77,215,169,205,184,210,117,162,35,107,121,131,116,29,83,245,174,43,196,153,142,174,99,145,174,139,11,197,133,108,23,138,116,93,164,235,202,86,170,185,119,29,98,6,109,174,42,176,111,204,172,159,82,37,246,141,25,181,223,115,102,223,152,41,
        190,87,129,125,99,6,248,94,21,246,141,25,183,125,171,192,190,49,179,182,111,206,236,27,55,107,34,88,141,125,227,102,189,185,156,217,55,94,67,239,186,124,35,62,123,215,33,110,209,37,205,117,19,202,172,251,241,195,111,21,80,105,102,26,90,85,136,68,110,
        86,169,42,208,117,124,185,156,55,67,215,49,253,43,208,235,185,205,204,226,107,206,35,93,119,143,232,58,22,120,103,30,196,98,51,201,230,159,251,136,116,93,109,116,29,11,29,119,101,177,239,64,243,9,25,233,186,218,232,58,22,120,171,44,196,147,152,144,141,
        39,100,164,235,106,163,235,120,232,141,64,120,108,4,178,46,9,25,233,58,0,186,142,7,222,187,14,241,40,234,172,75,66,70,186,174,122,239,58,196,67,23,117,120,20,117,214,37,33,239,13,93,231,179,119,29,15,93,212,225,81,212,105,62,33,215,40,141,106,163,235,
        24,68,135,170,162,21,103,62,131,65,116,168,202,239,184,64,120,4,209,23,173,104,197,221,35,16,94,144,129,240,130,12,132,23,100,16,157,222,138,86,220,61,130,232,244,150,139,38,0,30,113,144,46,98,28,162,191,96,126,213,9,225,17,72,101,224,32,149,129,131,
        84,6,14,82,25,56,72,101,224,32,149,129,131,84,6,238,90,25,166,133,18,0,137,96,16,237,165,74,246,197,150,174,83,91,177,165,235,212,30,217,210,117,106,43,182,116,29,3,33,32,213,86,108,233,58,181,149,6,232,58,6,209,232,173,196,138,45,93,167,182,98,77,215,
        113,144,230,95,106,43,77,208,117,234,61,177,166,235,56,72,113,81,91,177,166,235,212,102,172,233,58,14,82,118,213,86,172,233,58,181,25,107,186,142,131,148,41,181,21,107,186,78,109,198,145,174,163,73,71,90,108,144,174,75,133,130,174,43,140,137,142,174,
        43,62,58,23,233,186,184,80,92,40,210,117,85,4,202,72,215,213,218,187,78,152,118,77,171,192,239,9,131,174,105,21,248,61,97,214,52,173,18,191,39,12,122,166,85,224,247,132,105,7,193,10,252,158,48,235,152,230,204,239,9,227,142,105,21,248,61,97,212,49,205,
        157,223,19,198,189,185,42,240,123,98,185,55,23,40,191,151,153,182,125,171,194,239,101,102,173,16,157,249,189,204,184,21,98,5,142,43,51,106,133,232,78,8,102,166,173,16,171,224,110,217,114,98,255,232,24,196,102,232,58,161,127,193,107,61,183,153,69,124,
        137,107,164,235,238,17,93,39,66,239,204,35,98,103,158,230,159,251,136,116,93,109,116,157,8,189,51,143,136,157,121,154,79,200,72,215,213,70,215,137,208,59,243,136,216,153,167,249,132,140,116,93,109,116,157,8,189,51,143,136,157,121,214,37,33,35,93,7,64,
        215,101,161,119,230,201,162,168,179,46,9,25,233,58,0,186,46,11,93,212,201,162,168,179,46,9,121,111,232,58,159,189,235,178,208,69,157,44,138,58,205,39,228,26,165,81,109,116,157,0,233,126,84,176,226,204,103,20,172,56,19,39,2,164,47,154,0,233,139,38,64,
        250,162,9,144,190,104,2,164,47,154,0,233,139,38,64,250,162,9,144,190,104,2,164,47,154,0,233,139,38,64,250,162,9,144,190,104,25,72,101,200,64,42,67,6,82,25,50,144,202,144,129,84,134,12,164,50,100,32,149,33,3,169,12,153,107,101,152,22,74,0,36,66,40,105,
        28,107,43,43,90,128,153,209,117,106,43,182,116,157,218,35,91,186,78,109,197,150,174,19,32,61,205,212,86,108,233,58,181,149,6,232,58,1,210,209,76,109,197,150,174,83,91,177,166,235,4,72,67,51,181,149,38,232,58,245,158,88,211,117,25,72,113,81,91,177,166,
        235,212,102,172,233,186,12,164,236,170,173,88,211,117,106,51,214,116,93,6,82,166,212,86,172,233,58,181,25,71,186,142,200,107,64,68,154,163,235,112,194,20,116,93,97,104,53,116,29,78,120,185,167,145,174,139,11,197,133,34,93,119,55,163,35,93,167,93,169,
        230,222,117,56,49,232,69,228,206,190,225,196,172,105,90,21,246,45,223,134,71,246,13,35,179,150,105,85,216,183,124,27,62,217,55,140,140,59,166,185,179,111,249,70,124,178,111,24,153,118,76,171,192,190,229,27,241,201,190,97,100,214,9,177,18,251,150,111,
        196,39,251,134,145,105,43,68,103,50,13,99,101,214,253,232,184,49,64,84,58,47,229,222,97,190,124,92,252,246,174,203,131,43,136,222,117,242,120,54,79,215,225,36,190,196,53,210,117,247,135,174,147,147,185,176,159,251,192,119,4,215,152,144,110,169,19,233,
        186,245,160,235,228,165,73,232,9,25,59,243,52,159,144,145,174,171,139,174,147,151,217,161,39,100,236,204,211,124,66,70,186,174,46,186,14,163,192,59,243,96,20,59,243,172,75,66,70,186,174,58,93,135,81,224,157,121,48,138,162,206,186,36,100,164,235,170,211,
        117,24,133,46,234,224,40,234,172,75,66,222,27,186,206,99,239,58,140,67,23,117,112,20,117,154,79,200,53,74,163,186,232,186,252,166,96,117,62,163,104,197,149,207,40,90,113,37,78,242,59,46,16,30,65,244,69,43,90,113,246,8,65,244,69,43,90,113,246,8,65,244,
        69,203,53,63,8,143,32,250,162,21,173,184,123,4,209,23,173,104,197,221,35,136,190,104,249,85,39,132,71,32,149,1,129,84,6,4,82,25,16,72,101,64,32,149,1,131,84,6,12,82,25,176,107,101,152,22,202,234,72,68,126,2,129,176,178,162,5,152,17,93,87,98,197,146,174,
        43,241,200,146,174,43,177,98,73,215,229,165,31,224,232,170,173,88,210,117,37,86,234,167,235,242,179,7,196,65,89,217,92,208,128,174,43,177,98,75,215,229,167,15,8,151,86,119,34,171,135,174,43,217,19,91,186,46,63,7,65,28,150,213,61,209,140,114,113,117,79,
        52,147,194,128,64,202,174,218,138,45,93,87,98,198,150,174,203,207,67,0,62,169,173,216,210,117,37,102,220,232,58,70,68,7,161,164,65,186,142,96,5,93,87,56,12,58,186,142,144,114,79,35,93,23,23,138,11,69,186,238,110,70,71,186,78,187,82,173,189,235,48,49,
        237,154,86,129,223,35,6,93,211,42,240,123,196,172,105,90,37,126,143,24,244,76,171,192,239,17,179,150,105,149,248,61,98,214,49,205,153,223,163,198,29,211,42,240,123,212,172,99,154,51,191,71,141,59,166,85,224,247,168,81,199,52,119,126,143,154,118,76,171,
        194,239,81,163,86,136,238,112,29,53,237,34,88,133,20,163,203,57,241,227,199,247,170,80,149,212,184,65,101,5,186,142,46,23,219,102,232,58,162,127,193,107,61,183,153,73,124,137,107,164,235,238,17,93,71,2,239,204,131,73,236,204,211,252,115,31,145,174,171,
        141,174,35,129,119,230,193,36,118,230,105,62,33,35,93,87,27,93,71,3,239,204,131,105,236,204,211,124,66,70,186,174,54,186,142,6,222,153,7,211,216,153,103,93,18,50,210,117,0,116,29,13,188,51,15,166,81,212,89,151,132,140,116,221,83,33,47,30,81,50,99,121,
        40,73,100,130,90,38,100,232,162,14,141,162,206,186,36,228,189,161,235,60,246,174,195,52,116,81,135,70,81,167,249,132,92,163,52,170,141,174,35,16,221,143,138,86,156,249,12,2,209,23,45,191,227,2,225,17,68,95,180,162,21,119,143,32,250,162,21,173,184,123,
        4,209,23,45,215,252,0,60,42,88,113,246,168,96,197,221,35,136,190,104,69,43,238,30,65,244,69,203,175,58,33,60,2,169,12,20,164,50,80,144,202,64,65,42,3,5,169,12,20,164,50,80,144,202,64,93,43,195,180,80,2,32,17,4,162,109,81,201,190,216,210,117,106,43,182,
        116,157,218,35,91,186,78,109,197,150,174,35,16,61,205,74,172,216,210,117,106,43,13,208,117,84,105,197,246,160,168,173,216,210,117,106,43,214,116,29,133,104,104,86,98,165,9,186,78,189,39,214,116,29,5,41,46,106,43,214,116,157,218,140,53,93,71,65,202,174,
        218,138,53,93,167,54,99,77,215,81,144,50,165,182,98,77,215,169,205,56,210,117,52,235,32,220,36,93,199,50,5,93,87,216,127,29,93,199,147,114,79,35,93,23,23,138,11,69,186,238,110,70,71,186,78,187,210,106,186,238,199,15,128,84,192,5,185,105,163,185,10,184,
        32,55,104,223,84,1,23,228,102,125,230,42,225,130,220,160,205,92,5,92,144,155,117,153,171,132,11,114,179,38,115,206,184,32,55,110,50,87,1,23,228,102,77,230,156,113,65,110,218,100,174,10,46,200,13,122,71,86,193,5,83,179,156,174,134,11,166,166,61,217,92,
        157,48,238,30,89,1,76,75,141,186,71,186,51,143,169,105,247,200,42,204,99,186,156,216,205,208,117,92,255,130,215,122,110,51,243,248,18,215,72,215,221,35,186,142,135,222,153,135,199,206,60,205,63,247,17,233,186,218,232,58,30,122,103,30,30,59,243,52,159,
        144,145,174,171,141,174,227,161,119,230,225,177,51,79,243,9,25,233,186,218,232,58,30,122,103,158,52,137,9,185,38,9,25,233,58,0,186,46,13,189,51,79,26,69,157,117,73,200,72,215,1,244,174,75,67,23,117,210,40,234,172,75,66,222,27,186,206,103,239,186,52,116,
        81,39,141,162,78,243,9,185,70,105,84,27,93,199,65,186,31,113,144,238,71,28,164,47,26,7,233,139,198,65,250,162,113,144,190,104,28,164,47,26,7,233,139,198,65,250,162,113,144,190,104,28,164,47,26,7,233,139,198,65,250,162,113,144,190,104,28,164,47,90,10,
        82,25,82,144,202,144,130,84,134,20,164,50,164,32,149,33,5,169,12,41,72,101,72,65,42,67,234,90,25,166,133,18,0,137,224,32,109,139,212,251,98,75,215,169,173,216,210,117,106,143,108,233,58,181,21,91,186,142,131,244,52,83,91,177,165,235,212,86,26,160,235,
        56,72,71,51,181,21,91,186,78,109,197,154,174,227,32,13,205,212,86,154,160,235,212,123,98,77,215,165,32,197,69,109,197,154,174,83,155,177,166,235,82,144,178,171,182,98,77,215,169,205,88,211,117,41,72,153,82,91,177,166,235,212,102,220,232,58,138,228,53,
        32,198,117,210,117,123,155,199,39,59,71,19,185,229,184,213,106,109,190,252,253,243,151,199,251,155,123,59,249,95,99,74,103,123,231,213,238,86,254,231,198,195,133,191,91,27,27,51,98,104,119,130,249,20,22,159,127,253,89,123,119,115,171,179,61,148,142,12,
        59,147,39,249,148,203,125,210,222,235,159,245,191,233,125,184,110,181,78,114,230,111,235,96,239,112,188,71,71,155,219,7,91,47,115,9,165,53,30,132,147,163,131,23,47,118,142,246,54,15,15,119,247,191,206,23,121,181,187,51,59,160,31,143,165,164,238,249,201,
        176,123,121,157,31,128,231,221,225,228,200,188,235,159,157,245,46,183,206,251,87,215,227,75,232,243,241,161,188,253,251,172,127,61,22,73,142,229,117,252,233,187,23,253,215,195,238,176,223,155,124,55,213,154,164,209,211,239,78,186,111,39,31,158,222,12,
        135,189,203,209,113,255,172,119,216,189,236,157,231,234,193,100,229,214,40,95,112,52,184,202,47,252,229,145,111,189,151,3,146,51,80,185,68,245,235,228,105,70,120,154,8,193,147,148,101,52,163,104,252,253,112,34,241,252,162,77,248,211,132,19,156,33,68,
        50,76,19,134,229,49,26,31,145,157,237,221,147,131,163,220,225,252,183,189,221,223,231,66,201,228,24,189,220,222,61,200,63,148,7,100,124,200,142,54,247,191,222,57,58,153,176,147,15,102,71,120,115,40,143,202,219,222,176,53,21,173,144,204,218,141,7,75,154,
        214,198,252,107,177,8,95,201,113,217,217,59,60,40,26,253,168,253,245,249,224,117,247,124,110,18,35,173,73,76,138,38,247,54,143,190,185,221,209,233,82,73,146,182,102,230,247,186,195,239,228,30,107,108,38,73,86,180,185,245,219,131,163,237,226,110,62,105,
        111,189,203,117,172,249,110,232,29,199,119,28,255,234,224,197,246,124,47,31,207,183,91,104,244,152,131,168,157,95,119,68,171,247,195,85,247,242,44,207,210,141,7,11,57,58,211,240,62,126,244,127,95,252,239,179,127,251,239,189,103,23,55,163,41,81,186,241,
        184,176,133,246,124,11,116,186,133,191,106,143,99,175,179,123,121,221,27,142,174,87,111,99,240,199,63,255,233,151,223,62,123,182,241,147,82,201,50,73,138,53,123,186,241,39,243,175,69,43,231,252,94,229,149,100,246,108,30,194,236,110,9,25,47,115,240,230,
        205,117,111,52,89,138,176,140,164,119,22,107,157,14,206,7,55,195,60,8,223,200,159,130,168,249,241,163,127,127,114,243,151,191,252,199,230,179,229,163,89,168,114,27,143,203,125,185,51,239,41,67,6,103,186,242,163,249,122,250,27,61,139,91,95,142,151,219,
        173,219,190,124,116,182,31,63,153,91,152,189,206,241,113,59,31,232,214,184,210,76,63,64,9,78,138,187,149,215,146,175,134,131,139,201,95,227,202,49,251,19,143,191,60,25,44,124,53,249,163,48,3,58,27,126,208,72,170,223,207,134,82,249,173,246,64,216,190,
        99,110,105,64,216,236,69,179,79,218,231,189,247,178,170,186,140,7,179,29,143,9,5,59,59,211,21,190,219,216,152,157,169,166,181,228,243,246,151,103,189,55,221,155,243,81,167,123,115,214,31,76,217,238,95,105,147,137,5,144,76,216,52,153,152,122,20,87,142,
        221,138,71,225,13,7,143,87,78,166,249,3,135,202,100,146,51,235,245,72,38,235,199,18,239,14,8,74,0,146,9,37,182,119,182,124,39,147,28,194,230,147,137,24,38,19,114,60,51,33,164,127,227,182,225,224,85,62,51,33,164,75,38,180,46,103,38,84,249,204,132,230,
        61,9,170,36,147,117,223,0,239,201,68,105,243,201,68,77,147,169,228,45,239,171,199,78,255,8,186,233,224,185,22,228,121,50,209,76,151,76,108,77,206,76,136,217,62,159,187,52,32,60,3,72,38,235,199,132,189,39,83,138,154,79,38,102,154,76,37,15,117,174,28,187,
        20,228,204,148,86,62,51,165,186,107,38,148,138,53,73,166,212,246,69,249,75,3,146,113,128,100,202,108,119,195,123,50,101,1,92,51,113,211,100,202,220,174,153,112,162,127,244,219,108,240,112,98,251,124,246,221,100,194,9,209,36,19,78,216,122,36,19,78,108,
        159,139,93,26,16,76,170,39,19,198,182,187,225,59,153,48,102,205,39,83,106,152,76,24,171,47,57,87,143,157,190,7,131,233,224,185,94,42,204,147,137,36,186,100,34,120,77,146,137,216,118,29,92,26,16,150,0,36,19,179,221,13,239,201,196,112,243,201,36,76,147,
        137,169,47,57,87,143,157,254,145,107,211,193,179,85,143,150,146,137,233,4,136,252,125,160,235,145,76,172,170,154,135,211,20,32,153,82,219,221,0,79,38,227,0,76,103,215,136,237,246,251,211,174,147,183,194,26,36,85,221,135,147,201,221,154,189,250,50,79,
        192,163,222,121,247,67,241,38,220,109,198,182,242,159,127,125,254,108,113,15,203,111,194,97,81,156,185,149,108,159,172,218,190,242,38,224,172,120,104,183,79,181,149,78,248,155,54,116,187,242,163,197,186,54,118,171,163,114,96,241,88,62,210,248,98,55,109,
        152,87,24,161,189,95,160,146,56,243,186,241,168,253,235,133,42,50,254,107,177,248,144,98,241,161,138,26,83,82,69,166,53,166,164,2,105,195,221,103,114,127,210,30,63,214,208,185,35,27,44,69,76,230,41,98,186,221,252,236,168,136,24,236,30,49,153,157,56,63,
        143,152,12,217,68,204,114,144,40,35,134,21,35,166,16,204,250,152,208,199,147,46,98,50,219,11,71,167,136,33,218,136,201,136,167,136,73,146,113,196,232,103,83,147,24,42,222,206,209,69,140,250,202,110,117,196,48,231,26,179,24,35,105,49,70,196,157,216,170,
        35,98,124,222,14,156,71,140,254,172,148,249,186,1,152,71,76,183,107,20,49,212,56,98,212,69,121,117,196,232,238,21,104,31,9,201,22,131,100,252,76,176,230,156,229,63,100,72,226,83,167,159,135,12,211,133,12,73,124,41,243,73,146,159,152,140,66,134,25,134,
        12,41,145,243,86,133,12,209,138,120,154,144,25,63,170,93,140,25,220,116,204,248,84,208,230,49,163,125,2,142,36,190,38,191,249,7,134,49,195,141,99,198,109,242,75,18,235,201,239,60,70,200,157,152,161,77,199,76,45,211,223,84,31,51,254,166,191,198,49,147,
        154,198,140,229,179,41,243,152,65,86,211,223,66,204,176,59,49,195,27,142,25,84,203,4,88,104,99,6,249,154,0,79,206,78,70,49,35,140,99,198,109,2,76,144,245,4,120,30,35,233,157,152,17,77,199,76,45,83,96,183,27,138,100,254,188,214,10,213,172,252,93,22,4,
        85,120,31,226,35,243,119,89,148,116,106,41,125,151,133,90,28,35,40,243,37,142,17,156,104,243,22,251,123,218,3,92,28,35,216,113,78,137,181,115,74,213,195,180,97,138,99,196,235,61,89,51,113,140,120,187,11,235,65,28,35,150,119,97,111,35,198,234,241,235,
        112,197,49,130,107,153,79,106,197,49,130,125,205,39,61,136,99,132,56,206,39,137,118,62,169,173,49,65,137,99,132,212,50,155,212,138,99,132,248,148,83,129,197,49,66,28,103,147,68,59,155,212,33,30,161,137,99,164,150,201,164,94,28,35,254,244,84,120,113,140,
        184,233,169,132,104,245,212,242,144,9,80,28,163,181,8,170,122,113,140,250,19,84,225,197,49,234,56,249,165,214,147,223,96,197,49,90,203,244,87,47,142,81,127,211,95,120,113,140,58,78,127,169,35,125,24,160,56,102,13,188,120,16,199,168,175,9,176,15,113,172,
        4,140,89,25,51,204,122,2,28,172,56,198,106,153,2,59,138,99,140,84,22,199,88,133,55,47,215,47,142,49,182,66,28,123,232,44,142,49,253,252,128,249,131,116,87,138,99,95,180,9,147,155,75,8,71,148,11,202,144,72,51,68,211,212,60,143,29,231,152,76,203,247,173,
        207,147,100,132,215,50,195,212,139,101,220,215,12,211,64,44,171,28,65,37,109,48,87,70,16,215,205,56,151,34,40,96,241,204,186,237,160,7,241,140,251,187,129,95,16,207,202,163,165,130,152,86,210,38,110,117,4,89,3,251,129,138,105,214,239,191,240,32,166,113,
        159,242,235,194,236,211,38,130,140,197,181,18,62,122,101,4,165,186,217,168,246,149,15,161,137,107,214,125,107,60,136,107,169,63,61,182,32,174,217,132,144,177,216,86,210,103,100,117,8,233,244,89,77,8,5,40,182,89,119,118,240,32,182,165,254,4,218,130,112,
        98,19,67,198,226,91,9,114,180,58,134,172,39,211,193,138,111,214,28,146,7,241,77,248,155,78,59,199,144,177,24,39,28,167,211,194,106,58,29,180,24,39,106,153,80,235,197,56,143,56,88,65,140,179,137,33,227,75,50,71,60,140,104,241,48,125,12,133,38,206,213,
        3,136,57,138,115,194,144,247,212,136,115,37,60,87,160,226,92,182,10,43,117,23,231,50,189,180,226,13,185,170,67,156,115,68,176,136,22,193,82,190,124,43,80,113,174,30,4,107,69,4,249,154,145,214,33,206,57,34,89,68,139,100,45,69,80,184,226,28,173,135,200,
        210,138,115,212,35,145,229,93,156,163,142,132,22,213,18,90,250,26,20,148,56,71,235,225,179,180,226,28,245,200,103,121,23,231,168,35,175,69,181,188,150,246,21,146,129,137,115,180,30,92,75,43,206,81,111,184,86,13,226,28,117,196,183,168,22,223,210,132,80,
        120,226,28,173,7,223,210,138,115,212,27,190,149,127,224,89,156,163,142,56,23,213,226,92,250,24,10,76,156,163,245,224,92,90,113,142,34,127,211,105,239,226,28,45,225,197,86,199,144,227,219,144,195,19,231,40,174,101,66,173,21,231,168,71,28,205,187,56,71,
        29,241,52,170,197,211,244,49,20,152,56,71,235,1,212,220,196,57,138,89,85,113,142,150,240,100,97,138,115,20,167,190,196,57,138,87,228,177,191,39,94,189,139,115,212,17,1,163,90,4,76,249,50,239,48,197,57,90,15,2,166,21,231,168,55,4,172,6,113,142,58,34,97,
        84,139,132,45,69,80,192,226,92,61,68,152,94,156,243,72,132,249,23,231,28,9,49,170,37,196,244,53,40,44,113,174,30,62,76,47,206,121,228,195,252,139,115,142,188,24,213,242,98,218,150,20,161,137,115,245,224,98,122,113,206,27,46,86,135,56,231,136,143,81,45,
        62,166,9,161,0,197,185,122,240,49,189,56,231,13,31,203,63,240,45,206,57,226,100,84,139,147,233,99,40,52,113,174,30,156,76,47,206,49,127,211,105,255,226,92,9,175,182,58,134,172,166,211,65,139,115,214,61,8,60,136,115,30,113,56,255,226,156,35,14,71,245,
        56,156,54,134,66,19,231,234,1,226,28,197,57,142,42,139,115,37,188,90,160,226,28,95,213,16,193,93,156,227,250,203,26,111,72,89,29,226,156,35,82,70,181,72,153,178,57,88,160,226,92,61,72,153,94,156,227,13,54,72,168,28,65,142,72,25,213,34,101,75,17,20,176,
        56,87,15,81,166,23,231,60,18,101,254,197,57,71,162,140,106,137,50,125,13,10,75,156,171,135,39,211,159,197,60,242,100,254,197,57,71,158,140,106,121,50,109,139,203,208,196,185,122,112,50,189,56,231,13,39,171,67,156,115,196,201,168,22,39,211,132,80,128,
        226,92,61,56,153,94,156,243,134,147,229,31,248,22,231,28,113,50,170,197,201,244,49,20,154,56,87,15,78,166,23,231,60,246,27,243,47,206,57,246,31,163,218,254,99,250,24,10,77,156,171,167,3,153,94,156,243,136,195,249,23,231,28,113,56,170,197,225,244,49,20,
        154,56,87,15,16,231,40,206,101,149,27,50,208,18,94,45,80,113,46,91,213,144,193,89,156,99,119,184,181,59,121,204,188,33,101,53,136,115,204,17,41,99,90,164,76,217,108,60,76,113,142,213,131,148,105,197,57,230,13,41,171,65,156,99,142,72,25,211,34,101,75,
        17,20,174,56,199,234,33,202,180,226,28,243,72,148,121,23,231,152,35,81,198,180,68,153,190,6,5,37,206,177,122,120,50,173,56,199,60,242,100,222,197,57,230,200,147,49,45,79,166,140,160,64,197,57,86,15,78,166,21,231,152,55,156,172,6,113,142,57,226,100,76,
        139,147,105,66,40,60,113,142,213,131,147,105,197,57,230,13,39,203,63,240,44,206,49,71,156,140,105,113,50,125,12,5,38,206,177,122,112,50,173,56,199,60,246,59,243,46,206,49,199,254,103,76,219,255,76,31,67,129,137,115,172,158,14,104,90,113,142,121,196,225,
        188,139,115,204,17,135,99,90,28,78,31,67,129,137,115,172,30,32,206,77,156,99,164,114,67,8,86,194,171,133,41,206,49,226,173,33,4,35,250,249,132,55,164,172,14,113,206,17,41,99,90,164,12,179,108,109,196,185,122,144,50,189,56,231,13,41,171,67,156,115,68,
        202,152,22,41,91,138,160,128,197,185,122,136,50,189,56,231,145,40,243,47,206,57,18,101,76,75,148,233,107,80,88,226,92,61,60,153,94,156,243,200,147,249,23,231,28,121,50,166,229,201,148,17,20,170,56,87,15,78,166,23,231,188,225,100,117,136,115,142,56,25,
        211,226,100,154,16,10,80,156,171,7,39,211,79,166,189,225,100,249,7,190,197,57,71,156,140,105,113,50,125,12,133,38,206,213,131,147,233,197,57,143,253,213,252,139,115,142,253,213,152,182,191,154,62,134,66,19,231,234,233,176,166,23,231,60,226,112,254,197,
        57,71,28,142,233,113,56,109,12,133,38,206,213,3,196,57,138,115,188,114,67,8,86,194,171,53,46,206,25,31,131,212,16,237,213,140,177,53,178,166,49,85,188,188,46,72,140,243,154,32,175,160,38,227,255,36,79,202,222,245,130,140,248,15,231,255,245,63,255,252,
        159,207,158,45,232,141,15,22,12,94,203,2,144,255,150,140,127,219,149,255,116,71,211,131,167,19,30,213,243,237,159,206,191,230,126,207,115,167,55,195,97,239,114,180,41,7,251,176,59,236,94,156,116,223,202,157,107,47,184,61,248,227,159,255,244,203,111,159,
        61,211,248,119,113,51,249,45,89,60,118,197,26,112,119,59,135,231,55,111,251,151,187,219,121,108,36,191,73,180,165,238,206,84,192,60,252,196,52,252,158,180,207,123,239,123,231,110,1,168,206,127,152,34,243,121,251,203,179,222,155,238,205,249,168,211,189,
        57,235,15,58,131,155,209,213,205,232,87,170,144,248,100,182,71,34,241,123,218,186,29,104,117,16,24,12,61,54,61,139,9,199,202,34,48,192,208,10,18,200,208,126,60,223,35,234,113,104,243,21,231,163,181,52,144,203,99,189,56,160,198,58,159,96,142,3,202,33,
        6,84,93,40,154,28,80,17,232,128,26,203,110,194,113,254,147,37,0,3,154,169,203,67,131,3,154,97,191,34,188,243,128,26,139,96,153,186,234,173,30,80,10,49,160,234,242,208,228,128,250,155,96,85,27,80,99,69,42,115,156,30,101,16,211,163,44,180,233,17,79,252,
        77,143,198,183,234,1,166,71,166,66,17,79,220,166,71,60,1,152,30,241,36,148,233,209,79,231,123,228,121,122,228,241,98,168,32,85,84,184,24,226,137,219,4,139,39,0,19,44,158,52,62,193,50,247,87,84,213,95,120,98,91,219,20,250,75,126,175,121,22,62,249,211,
        46,213,85,21,142,146,170,170,10,71,182,243,170,105,38,206,246,33,33,133,121,237,199,179,76,44,166,222,39,243,212,83,157,24,55,218,75,251,183,49,51,79,147,197,227,113,123,12,30,78,28,255,168,253,126,112,126,35,99,102,190,60,41,30,6,133,239,183,182,169,
        218,225,165,173,204,18,101,190,98,106,177,17,81,182,145,98,70,44,100,193,198,138,44,88,26,3,134,220,199,96,58,219,212,141,1,35,118,99,192,184,249,225,97,169,227,24,240,196,124,35,188,36,178,33,199,128,211,106,99,208,237,106,199,128,115,187,49,224,153,
        249,225,73,19,199,49,72,45,146,45,45,77,54,184,49,40,190,15,202,118,12,198,79,29,232,198,32,205,236,198,64,96,243,195,35,136,227,24,8,139,100,19,165,201,6,55,6,89,82,101,12,198,74,180,110,12,228,85,183,213,24,100,204,252,240,100,220,113,12,50,243,100,
        67,73,105,178,129,141,129,60,41,87,57,39,175,26,3,89,180,173,198,64,198,157,197,225,201,220,198,0,33,243,100,67,168,52,217,220,199,224,255,1,148,170,60,43,0,0 };

        const auto editName = "RackMixBus";
        auto edit = openEditFromZipData (engine, RackMixBus_zip, sizeof (RackMixBus_zip));
        const double fileLength = 20.0;
        auto sinFile = test_utilities::getSinFile<juce::WavAudioFormat> (ts.sampleRate, fileLength, 2);
        
        beginTest ("Load Edit");
        {
            expect (edit != nullptr);

            // Put the content on the first 8 audio tracks
            auto audioTracks = getAudioTracks (*edit);
            expectGreaterOrEqual (audioTracks.size(), 8);
            
            for (int i = 0; i < 8; ++i)
                audioTracks[i]->insertMIDIClip (EditTimeRange::withStartAndLength (0.0, fileLength), nullptr);

            expectEquals (edit->getLength(), fileLength);
        }

        // Render single threaded first
        renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::no, LockFree::no, ThreadPoolStrategy::conditionVariable });
        renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::no, LockFree::yes, ThreadPoolStrategy::conditionVariable });

        // Then multi threaded with different strategies
        renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::no, ThreadPoolStrategy::lightweightSemaphore });

        for (auto strategy : test_utilities::getThreadPoolStrategies())
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, strategy });

        // Directly compare not-pooled
        {
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::semaphore, PoolMemoryAllocations::no });
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemaphore, PoolMemoryAllocations::no });
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemHybrid, PoolMemoryAllocations::no });
        }

       #if TRACKTION_GRAPH_ADVANCED_PERFORMANCE_TESTS
        // Then multi threaded with pooled memory
        {
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::semaphore, PoolMemoryAllocations::yes });
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemaphore, PoolMemoryAllocations::yes });
            renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemHybrid, PoolMemoryAllocations::yes });
        }
       #endif

        // Lightweight semaphore seems to have the best performance so compare this over different buffer sizes
        {
            for (int blockSize : { 128, 256, 512, 1024, 2048 })
            {
                ts.blockSize = blockSize;
                renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemaphore, PoolMemoryAllocations::no });
                renderEdit (*this, { edit.get(), editName, ts, MultiThreaded::yes, LockFree::yes, ThreadPoolStrategy::lightweightSemaphore, PoolMemoryAllocations::yes });
            }
        }
    }
};

static RackBenchmarks rackBenchmarks;

}

#endif
