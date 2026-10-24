.setcpu "65816"
.segment "CODE"
.org $11D3
map_control_0e11d3:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
