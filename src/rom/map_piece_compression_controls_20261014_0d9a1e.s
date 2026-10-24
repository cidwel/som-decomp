.setcpu "65816"
.segment "CODE"
.org $9A1E
map_control_0d9a1e:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
