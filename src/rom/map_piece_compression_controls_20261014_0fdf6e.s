.setcpu "65816"
.segment "CODE"
.org $DF6E
map_control_0fdf6e:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
