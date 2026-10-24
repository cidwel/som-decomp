.setcpu "65816"
.segment "CODE"
.org $F81F
map_control_0df81f:
    .byte $C1 ; same-value copy count/distance
    .byte $EF ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $F2 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
