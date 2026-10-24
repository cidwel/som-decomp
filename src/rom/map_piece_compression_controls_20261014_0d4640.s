.setcpu "65816"
.segment "CODE"
.org $4640
map_control_0d4640:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
