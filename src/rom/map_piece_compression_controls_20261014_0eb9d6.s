.setcpu "65816"
.segment "CODE"
.org $B9D6
map_control_0eb9d6:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
