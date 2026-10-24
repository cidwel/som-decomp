.setcpu "65816"
.segment "CODE"
.org $54C6
map_control_0d54c6:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
