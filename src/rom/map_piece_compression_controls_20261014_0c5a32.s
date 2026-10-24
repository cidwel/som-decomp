.setcpu "65816"
.segment "CODE"
.org $5A32
map_control_0c5a32:
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
