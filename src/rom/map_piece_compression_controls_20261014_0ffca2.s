.setcpu "65816"
.segment "CODE"
.org $FCA2
map_control_0ffca2:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C3 ; same-value copy count/distance
