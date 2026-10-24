.setcpu "65816"
.segment "CODE"
.org $2EA4
map_control_0d2ea4:
    .byte $ED ; backreference distance high bits
    .byte $83 ; distance low bit/count
