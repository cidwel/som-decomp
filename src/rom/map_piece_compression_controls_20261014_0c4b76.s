.setcpu "65816"
.segment "CODE"
.org $4B76
map_control_0c4b76:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
