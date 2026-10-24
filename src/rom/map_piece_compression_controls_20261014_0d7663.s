.setcpu "65816"
.segment "CODE"
.org $7663
map_control_0d7663:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
