.setcpu "65816"
.segment "CODE"
.org $B29F
map_control_0db29f:
    .byte $F1 ; progressive-copy count
    .byte $ED ; backreference distance high bits
    .byte $02 ; distance low bit/count
