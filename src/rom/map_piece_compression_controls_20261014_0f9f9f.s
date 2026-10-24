.setcpu "65816"
.segment "CODE"
.org $9F9F
map_control_0f9f9f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $0D ; distance low bit/count
