.setcpu "65816"
.segment "CODE"
.org $4DFC
map_control_0e4dfc:
    .byte $F1 ; progressive-copy count
    .byte $EA ; backreference distance high bits
    .byte $02 ; distance low bit/count
