# $10 USB Handbrake

This is the cheapest DIY 3D printed handbrake for pc games using an Arduino Pro micro

Thanks to Jonj57 for providing the 3d print files over on [thingiverse](https://www.thingiverse.com/thing:5213117).

Thanks to AM-STUDIO for providing the Joystick library on [github](https://github.com/AM-STUDIO/Analog-E-Brake/tree/master/Joystick)

My addition to the project is providing a handy arduino sketch for configuring the deadzone and being able to flip the output of the hand brake, as well as a more noob friendly guide on how to do the whole thing.

2026 update I added a new mode where instead of outputting the handbrake as an axis, it outputs it as a button press. This is useful for games that dont support proper handbrakes and just want a simple on/off button. You can switch between modes on the fly, see the 2026 update section below for more details.

# Parts list

All parts I got from Aliexpress since its the cheapest

| **Type**    | **Description**                                             | **Price**                        |
|-------------|-------------------------------------------------------------|----------------------------------|
| Needed      | Arduino Pro Micro USB C ATMEGA32U4 5V 16Mhz                | €3.99                            |
| Optional    | Tension spring wire 1m (can use rubber bands instead)      | €2.52                            |
| Needed      | Potentiometer resistor 10k 3pin Linear Rotary               | €1.68 for 10 pieces (only need 1) |
| Needed      | 1x M5x15, 4x M4x10, 4x M4x20, 2x M4x12, 3x M5x? for mount | ?                                |
| Needed      | PLA+ fillament | ?                                |

# Guide on Youtube

See the following video on how to assemble and test the handbrake.

The video is a bit out of date as it doesnt feature the new button mode. See the 2026 update section.

[![guide](https://img.youtube.com/vi/Eo_is477bk0/0.jpg)](https://www.youtube.com/watch?v=Eo_is477bk0)

### Video contents

1. Components + tools
2. Wiring
3. Software configuration
4. Using in Games (BeamNG)
5. Configuring Hanbrake with deadzones, flip
6. 3D print guide
7. Assembly

# 2026 update

Moved the files into a new folder so that arduino picks it up as a proper project.

Added a new mode where instead of outputting the handbrake as an axis, it outputs it as a button press. This is useful for games that dont support proper handbrakes and just want a simple on/off button. You can switch between modes on the fly by moving the potentiometer all the way to one side, see the setupMode function in the code.

To switch modes it depends on the starting position of the potentiometer once you plug the usb cable into the pc.

If you dont touch the handbrake and plug it in, it will run in the default axis mode, where the handbrake is outputted as an axis. This is the mode that is compatible with most games and is the default mode.

If you have the handbrake fully pulled and then plug it in, it will run in button mode, where the handbrake is outputted as a button press. This is useful for games that dont support proper handbrakes and just want a simple on/off button.

By default the button mode outputs the "A" button on an xbox controller, but you can change this in the code by changing the buttonToPress variable.

If you want the button mode to be more or less sensitive, you can change the buttonDeadZone variable in the code. This variable determines how far you need to pull the handbrake before it registers as a button press. Reduce this value if you want a more sensitive button output, increase it if you want a less sensitive button output.