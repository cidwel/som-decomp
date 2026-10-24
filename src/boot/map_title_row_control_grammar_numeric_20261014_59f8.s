; Native row syntax/geometry controls only: no glyph bytes or strings.
.setcpu "65816"
.segment "RODATA"
.org $59F8
row_control_59f8:
    .byte $06 ; leading blank count
