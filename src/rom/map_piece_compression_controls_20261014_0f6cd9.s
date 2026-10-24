.setcpu "65816"
.segment "CODE"
.org $6CD9
map_control_0f6cd9:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $21 ; distance low bit/count
