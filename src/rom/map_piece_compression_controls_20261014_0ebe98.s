.setcpu "65816"
.segment "CODE"
.org $BE98
map_control_0ebe98:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
