.setcpu "65816"
.segment "CODE"
.org $3BD8
map_control_0e3bd8:
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
