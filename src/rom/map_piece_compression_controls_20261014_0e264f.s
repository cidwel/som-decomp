.setcpu "65816"
.segment "CODE"
.org $264F
map_control_0e264f:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
