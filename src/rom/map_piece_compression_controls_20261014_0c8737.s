.setcpu "65816"
.segment "CODE"
.org $8737
map_control_0c8737:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $90 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
