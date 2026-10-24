.setcpu "65816"
.segment "CODE"
.org $4B03
map_control_0d4b03:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
