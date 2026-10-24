.setcpu "65816"
.segment "CODE"
.org $186E
map_control_0c186e:
    .byte $EE ; backreference distance high bits
    .byte $06 ; distance low bit/count
