.setcpu "65816"
.segment "CODE"
.org $3EDD
map_control_0c3edd:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
