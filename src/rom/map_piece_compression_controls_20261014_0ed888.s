.setcpu "65816"
.segment "CODE"
.org $D888
map_control_0ed888:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
