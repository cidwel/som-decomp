.setcpu "65816"
.segment "CODE"
.org $12C0
map_control_0d12c0:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
