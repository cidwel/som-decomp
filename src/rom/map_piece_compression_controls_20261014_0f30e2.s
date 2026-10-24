.setcpu "65816"
.segment "CODE"
.org $30E2
map_control_0f30e2:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
