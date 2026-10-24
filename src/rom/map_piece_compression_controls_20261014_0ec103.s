.setcpu "65816"
.segment "CODE"
.org $C103
map_control_0ec103:
    .byte $ED ; backreference distance high bits
    .byte $87 ; distance low bit/count
