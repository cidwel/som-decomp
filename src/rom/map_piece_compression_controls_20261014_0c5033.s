.setcpu "65816"
.segment "CODE"
.org $5033
map_control_0c5033:
    .byte $E8 ; backreference distance high bits
    .byte $40 ; distance low bit/count
