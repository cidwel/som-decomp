.setcpu "65816"
.segment "CODE"
.org $BB3A
map_control_0ebb3a:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
