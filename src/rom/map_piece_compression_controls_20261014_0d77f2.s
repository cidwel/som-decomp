.setcpu "65816"
.segment "CODE"
.org $77F2
map_control_0d77f2:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3F ; distance low bit/count
