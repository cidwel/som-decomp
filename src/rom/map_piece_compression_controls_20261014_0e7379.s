.setcpu "65816"
.segment "CODE"
.org $7379
map_control_0e7379:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
