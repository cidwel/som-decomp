.setcpu "65816"
.segment "CODE"
.org $50E4
map_control_0e50e4:
    .byte $C2 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
