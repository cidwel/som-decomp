.setcpu "65816"
.segment "CODE"
.org $F447
map_control_0df447:
    .byte $ED ; backreference distance high bits
    .byte $84 ; distance low bit/count
