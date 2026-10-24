; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $5A28
row_control_5a28:
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $09 ; leading blank count
