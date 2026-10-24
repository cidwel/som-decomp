.setcpu "65816"
.segment "CODE"
.org $2002
map_control_0d2002:
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
