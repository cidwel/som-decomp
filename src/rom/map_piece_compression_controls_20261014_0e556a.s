.setcpu "65816"
.segment "CODE"
.org $556A
map_control_0e556a:
    .byte $F2 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
