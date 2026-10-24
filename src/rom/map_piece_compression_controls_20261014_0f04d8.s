.setcpu "65816"
.segment "CODE"
.org $04D8
map_control_0f04d8:
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
