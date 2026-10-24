.setcpu "65816"
.segment "CODE"
.org $60AD
map_control_0e60ad:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
