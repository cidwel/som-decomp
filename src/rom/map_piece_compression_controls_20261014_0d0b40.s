.setcpu "65816"
.segment "CODE"
.org $0B40
map_control_0d0b40:
    .byte $D9 ; same-value copy count/distance
    .byte $D9 ; same-value copy count/distance
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
