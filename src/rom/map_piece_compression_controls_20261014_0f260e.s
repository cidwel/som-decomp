.setcpu "65816"
.segment "CODE"
.org $260E
map_control_0f260e:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
