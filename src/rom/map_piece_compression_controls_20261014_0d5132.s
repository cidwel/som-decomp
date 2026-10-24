.setcpu "65816"
.segment "CODE"
.org $5132
map_control_0d5132:
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
