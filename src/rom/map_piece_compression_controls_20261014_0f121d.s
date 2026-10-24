.setcpu "65816"
.segment "CODE"
.org $121D
map_control_0f121d:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $D1 ; same-value copy count/distance
