.setcpu "65816"
.segment "CODE"
.org $242D
map_control_0e242d:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
