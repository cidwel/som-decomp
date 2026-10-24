.setcpu "65816"
.segment "CODE"
.org $6E4D
map_control_0f6e4d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
