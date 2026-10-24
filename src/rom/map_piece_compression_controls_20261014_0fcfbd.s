.setcpu "65816"
.segment "CODE"
.org $CFBD
map_control_0fcfbd:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $CD ; same-value copy count/distance
