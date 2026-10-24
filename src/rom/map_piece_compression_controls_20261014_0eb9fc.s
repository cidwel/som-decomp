.setcpu "65816"
.segment "CODE"
.org $B9FC
map_control_0eb9fc:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
