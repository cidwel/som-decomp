.setcpu "65816"
.segment "CODE"
.org $7781
map_control_0f7781:
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $17 ; distance low bit/count
