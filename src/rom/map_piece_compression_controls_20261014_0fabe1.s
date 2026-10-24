.setcpu "65816"
.segment "CODE"
.org $ABE1
map_control_0fabe1:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
