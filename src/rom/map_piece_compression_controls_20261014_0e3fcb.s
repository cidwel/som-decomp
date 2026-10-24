.setcpu "65816"
.segment "CODE"
.org $3FCB
map_control_0e3fcb:
    .byte $EF ; backreference distance high bits
    .byte $87 ; distance low bit/count
