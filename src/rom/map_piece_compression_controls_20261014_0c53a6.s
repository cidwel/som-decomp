.setcpu "65816"
.segment "CODE"
.org $53A6
map_control_0c53a6:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
