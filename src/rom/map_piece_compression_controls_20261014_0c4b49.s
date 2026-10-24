.setcpu "65816"
.segment "CODE"
.org $4B49
map_control_0c4b49:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
