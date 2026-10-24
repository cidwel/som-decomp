.setcpu "65816"
.segment "CODE"
.org $6B22
map_control_0f6b22:
    .byte $EB ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3C ; distance low bit/count
