.setcpu "65816"
.segment "CODE"
.org $8EC3
map_control_0f8ec3:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $09 ; distance low bit/count
