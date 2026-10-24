.setcpu "65816"
.segment "CODE"
.org $8DA2
map_control_0e8da2:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
