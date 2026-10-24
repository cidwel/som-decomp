.setcpu "65816"
.segment "CODE"
.org $1FEE
map_control_0f1fee:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $30 ; distance low bit/count
