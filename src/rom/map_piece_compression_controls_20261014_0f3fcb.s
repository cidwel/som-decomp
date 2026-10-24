.setcpu "65816"
.segment "CODE"
.org $3FCB
map_control_0f3fcb:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $19 ; distance low bit/count
