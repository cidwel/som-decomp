.setcpu "65816"
.segment "CODE"
.org $8562
map_control_0d8562:
    .byte $CB ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
