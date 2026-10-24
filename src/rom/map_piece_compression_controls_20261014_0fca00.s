.setcpu "65816"
.segment "CODE"
.org $CA00
map_control_0fca00:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
