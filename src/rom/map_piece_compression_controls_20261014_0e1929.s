.setcpu "65816"
.segment "CODE"
.org $1929
map_control_0e1929:
    .byte $D9 ; same-value copy count/distance
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $87 ; distance low bit/count
