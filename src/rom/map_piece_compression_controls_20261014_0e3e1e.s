.setcpu "65816"
.segment "CODE"
.org $3E1E
map_control_0e3e1e:
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $02 ; distance low bit/count
