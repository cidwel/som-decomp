.setcpu "65816"
.segment "CODE"
.org $6197
map_control_0f6197:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $7C ; distance low bit/count
