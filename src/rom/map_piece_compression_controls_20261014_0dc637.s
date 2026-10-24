.setcpu "65816"
.segment "CODE"
.org $C637
map_control_0dc637:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C7 ; same-value copy count/distance
