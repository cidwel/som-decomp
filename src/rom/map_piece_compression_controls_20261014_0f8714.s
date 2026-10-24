.setcpu "65816"
.segment "CODE"
.org $8714
map_control_0f8714:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
