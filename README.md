# tat - Text Attributes for Terminal
### By ZeekHalkyr

This plugin unlocks some ANSI Escape Sequences in a easy to use format for batch programs.

## Usage

```tat <attributes>```

## Attributes and their behavior.
Attributes can be supplied in any order and are separated by spaces. If you call tat and do not supply an attribute, it is automatically disabled. E.g, calling ``tat dim`` and then calling ``tat underline`` will disable dim. To avoid this, make sure to include all the formatting you want in each call, e.g ``tat underline dim``.

### The full list of attributes:

**bold** - Bold is not noticeable on the command interpreter. It is used to undo the dim attribute. 

un͟d͟e͟r͟l͟i͟n͟e͟ - adds an underline to text. This is the small version of the underline (1/2 bigunderline)<sup>*</sup>

blink - The foreground text will flash between 'bold' (default) and 'dim' at a slow pace (fast blink not supported in Windows)

negative - The text will be inverted (foreground color will be background, background will be foreground)

dim - The text will be dimmed, use the bold attribute to undo this. 

bigun͟d͟e͟r͟l͟i͟n͟e͟ - adds a large underline (2x the size of underline) to the text<sup>*</sup>

~~strikethrough~~ - adds a strikethrough to the text<sup>*</sup>

overline - adds an overline to the text<sup>*</sup>

italic - *Slants the text and makes it noticeably sharper*<sup>*</sup>

*<sup>These attributes will populate the entire row when the screen is *resized horizontally*. This is a behavior of the windows console host and out of my control.</sup>





