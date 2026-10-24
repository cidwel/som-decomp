.setcpu "65816"
.segment "CODE"
.org $5B68
map_control_0f5b68:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
