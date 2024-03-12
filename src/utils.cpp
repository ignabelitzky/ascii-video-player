#include "../include/utils.hpp"

char intensityToASCII(int intensity)
{
    // std::string density = " .:-=+*#%@";
    std::string density = "@%#*+=-:. ";
    int index = intensity * density.size() / 256;
    return density[index];
}

void show_usage(std::string programName)
{
    std::cerr << "Usage: " << programName << " <path_to_video_file>" << std::endl;
}

bool check_input(int &argc, char **&argv)
{
    bool result = true;
    if (argc != 2)
    {
        show_usage(std::string(argv[0]));
        result = false;
    }
    return result;
}

void data_callback(ma_device *pDevice, void *pOutput, const void *pInput, ma_uint32 frameCount)
{
    ma_decoder *pDecoder = (ma_decoder *)pDevice->pUserData;
    if (pDecoder == NULL)
    {
        return;
    }

    ma_decoder_read_pcm_frames(pDecoder, pOutput, frameCount, NULL);

    (void)pInput;
}