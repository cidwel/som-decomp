.setcpu "65816"
.segment "CODE"
.org $52B9
map_control_0d52b9:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
