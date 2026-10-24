.setcpu "65816"
.segment "CODE"
.org $9204
map_control_0d9204:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
