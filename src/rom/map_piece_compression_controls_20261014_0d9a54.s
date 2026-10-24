.setcpu "65816"
.segment "CODE"
.org $9A54
map_control_0d9a54:
    .byte $EE ; backreference distance high bits
    .byte $03 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
