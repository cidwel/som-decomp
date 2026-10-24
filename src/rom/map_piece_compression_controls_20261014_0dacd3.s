.setcpu "65816"
.segment "CODE"
.org $ACD3
map_control_0dacd3:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
