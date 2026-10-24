.setcpu "65816"
.segment "CODE"
.org $6F51
map_control_0e6f51:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
