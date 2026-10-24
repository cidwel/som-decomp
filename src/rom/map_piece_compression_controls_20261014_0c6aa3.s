.setcpu "65816"
.segment "CODE"
.org $6AA3
map_control_0c6aa3:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
