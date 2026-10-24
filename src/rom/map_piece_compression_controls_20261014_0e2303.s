.setcpu "65816"
.segment "CODE"
.org $2303
map_control_0e2303:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
