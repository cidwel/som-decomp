.setcpu "65816"
.segment "CODE"
.org $EB57
map_control_0deb57:
    .byte $CA ; same-value copy count/distance
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
