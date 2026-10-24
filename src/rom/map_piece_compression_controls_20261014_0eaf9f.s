.setcpu "65816"
.segment "CODE"
.org $AF9F
map_control_0eaf9f:
    .byte $EF ; backreference distance high bits
    .byte $8D ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
