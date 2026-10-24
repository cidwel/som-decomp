.setcpu "65816"
.segment "CODE"
.org $655D
map_control_0e655d:
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C5 ; same-value copy count/distance
