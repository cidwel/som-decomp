.setcpu "65816"
.segment "CODE"
.org $3C6A
map_control_0e3c6a:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
