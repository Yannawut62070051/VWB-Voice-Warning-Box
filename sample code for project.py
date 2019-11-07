"""for tell you so loud when your voice so loud"""
def check():
    """for check your voice level is loud or not"""
    voice_level = float(input()) # input voice level in decibel
    timetoalert = int(input()) # counting how long is a voice lound
    if voice_level > 60: # check voice level
        if timetoalert >= 5: # alert start when it's long than 5 second
            print('Alert messages lound %.2f'% (voice_level)) # output by message you setup with voice level equal voice input
check()
