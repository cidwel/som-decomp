.setcpu "65816"
.segment "CODE"
.org $659C
map_control_0e659c:
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
