.setcpu "65816"
.segment "CODE"
.org $3F07
map_control_0c3f07:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
