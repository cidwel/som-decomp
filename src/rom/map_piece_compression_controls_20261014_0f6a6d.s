.setcpu "65816"
.segment "CODE"
.org $6A6D
map_control_0f6a6d:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $15 ; distance low bit/count
