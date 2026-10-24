.setcpu "65816"
.segment "CODE"
.org $8D63
map_control_0e8d63:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
