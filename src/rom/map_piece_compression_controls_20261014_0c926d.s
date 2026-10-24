.setcpu "65816"
.segment "CODE"
.org $926D
map_control_0c926d:
    .byte $E8 ; backreference distance high bits
    .byte $84 ; distance low bit/count
