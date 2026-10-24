.setcpu "65816"
.segment "CODE"
.org $855F
map_control_0c855f:
    .byte $EF ; backreference distance high bits
    .byte $8A ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $36 ; distance low bit/count
