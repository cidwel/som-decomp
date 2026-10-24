.setcpu "65816"
.segment "CODE"
.org $9A5D
map_control_0d9a5d:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
