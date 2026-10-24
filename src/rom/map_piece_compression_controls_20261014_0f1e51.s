.setcpu "65816"
.segment "CODE"
.org $1E51
map_control_0f1e51:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $33 ; distance low bit/count
