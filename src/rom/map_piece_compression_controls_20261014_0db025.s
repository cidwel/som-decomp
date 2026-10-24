.setcpu "65816"
.segment "CODE"
.org $B025
map_control_0db025:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
