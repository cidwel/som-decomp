.setcpu "65816"
.segment "CODE"
.org $684D
map_control_0f684d:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $10 ; distance low bit/count
