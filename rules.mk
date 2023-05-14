BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no        # Enable WS2812 RGB underlight.
SWAP_HANDS_ENABLE = no      # Enable one-hand typing
MUSIC_ENABLE = no           # No music
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

OLED_ENABLE= yes            # OLED display
OLED_DRIVER_ENABLE = yes    # Enable OLED driver
OLED_DRIVER = SSD1306       # Use SSD1306 driver
WPM_ENABLE = yes            # Enable WPM
ENCODER_ENABLE = yes        # Enable Encoder
SEND_STRING_ENABLE = yes    # Enable SEND_STRING
LTO_ENABLE = yes

# If you want to change the display of OLED, you need to change here
SRC +=  ./lib/host_led_state_reader.c \
