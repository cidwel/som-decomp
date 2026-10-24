.setcpu "65816"
.segment "CODE"
.org $5412
map_control_0c5412:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
