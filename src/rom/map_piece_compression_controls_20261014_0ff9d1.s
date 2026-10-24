.setcpu "65816"
.segment "CODE"
.org $F9D1
map_control_0ff9d1:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
