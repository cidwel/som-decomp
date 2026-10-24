.setcpu "65816"
.segment "CODE"
.org $5379
map_control_0d5379:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
