.setcpu "65816"
.segment "CODE"
.org $C010
map_control_0dc010:
    .byte $F1 ; progressive-copy count
    .byte $EC ; backreference distance high bits
    .byte $02 ; distance low bit/count
