.setcpu "65816"
.segment "CODE"
.org $B147
map_control_0fb147:
    .byte $C3 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
