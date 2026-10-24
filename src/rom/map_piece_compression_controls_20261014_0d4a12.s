.setcpu "65816"
.segment "CODE"
.org $4A12
map_control_0d4a12:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
