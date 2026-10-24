.setcpu "65816"
.segment "CODE"
.org $DEC8
map_control_0edec8:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
