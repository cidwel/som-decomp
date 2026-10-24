.setcpu "65816"
.segment "CODE"
.org $585E
map_control_0d585e:
    .byte $E9 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $07 ; distance low bit/count
