; Actual secondary-row grammar/geometry controls only.
.setcpu "65816"
.segment "RODATA"
.org $5C0B
row_secondary_control_5c0b:
    .byte $00 ; row terminator
    .byte $00 ; stream terminator
    .byte $02 ; leading blank count
