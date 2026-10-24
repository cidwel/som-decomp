.setcpu "65816"
.segment "CODE"
.org $4B9D
map_control_0c4b9d:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
