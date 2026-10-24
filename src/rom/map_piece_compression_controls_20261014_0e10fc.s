.setcpu "65816"
.segment "CODE"
.org $10FC
map_control_0e10fc:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $4F ; distance low bit/count
