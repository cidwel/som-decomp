; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $5B41
row_control_5b41:
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $01 ; leading blank count
    .byte $00 ; row terminator
    .byte $06 ; leading blank count
