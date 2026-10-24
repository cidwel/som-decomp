.setcpu "65816"
.segment "CODE"
.org $3784
map_control_0e3784:
    .byte $F2 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $02 ; distance low bit/count
