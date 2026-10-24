.setcpu "65816"
.segment "CODE"
.org $D8D4
map_control_0fd8d4:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
