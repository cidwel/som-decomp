.setcpu "65816"
.segment "CODE"
.org $23E9
map_control_0c23e9:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $1C ; distance low bit/count
