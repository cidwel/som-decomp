.setcpu "65816"
.segment "CODE"
.org $4350
map_control_0d4350:
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
