.setcpu "65816"
.segment "CODE"
.org $39DB
map_control_0e39db:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
