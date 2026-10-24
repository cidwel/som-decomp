.setcpu "65816"
.segment "CODE"
.org $1E47
map_control_0f1e47:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $18 ; distance low bit/count
