.setcpu "65816"
.segment "CODE"
.org $DD04
map_control_0edd04:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
