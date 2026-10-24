.setcpu "65816"
.segment "CODE"
.org $7DC3
map_control_0c7dc3:
    .byte $EF ; backreference distance high bits
    .byte $04 ; distance low bit/count
