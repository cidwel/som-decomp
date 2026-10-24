.setcpu "65816"
.segment "CODE"
.org $1E60
map_control_0d1e60:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $88 ; distance low bit/count
