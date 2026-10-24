.setcpu "65816"
.segment "CODE"
.org $8364
map_control_0e8364:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
