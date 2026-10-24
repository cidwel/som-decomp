.setcpu "65816"
.segment "CODE"
.org $1C01
map_control_0c1c01:
    .byte $F1 ; progressive-copy count
    .byte $E9 ; backreference distance high bits
    .byte $02 ; distance low bit/count
