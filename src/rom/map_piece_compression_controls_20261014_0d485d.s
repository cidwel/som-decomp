.setcpu "65816"
.segment "CODE"
.org $485D
map_control_0d485d:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
