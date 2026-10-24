.setcpu "65816"
.segment "CODE"
.org $E4CF
map_control_0ee4cf:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
