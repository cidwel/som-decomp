.setcpu "65816"
.segment "CODE"
.org $E4DC
map_control_0ee4dc:
    .byte $C4 ; same-value copy count/distance
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
