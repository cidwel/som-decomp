.setcpu "65816"
.segment "CODE"
.org $92C7
map_control_0f92c7:
    .byte $C9 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
