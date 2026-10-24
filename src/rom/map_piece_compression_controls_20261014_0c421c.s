.setcpu "65816"
.segment "CODE"
.org $421C
map_control_0c421c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $83 ; distance low bit/count
