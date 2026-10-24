.setcpu "65816"
.segment "CODE"
.org $4CAF
map_control_0c4caf:
    .byte $EF ; backreference distance high bits
    .byte $05 ; distance low bit/count
