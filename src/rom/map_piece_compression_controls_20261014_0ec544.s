.setcpu "65816"
.segment "CODE"
.org $C544
map_control_0ec544:
    .byte $C6 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
