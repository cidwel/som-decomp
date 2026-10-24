.setcpu "65816"
.segment "CODE"
.org $3ABE
map_control_0e3abe:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
