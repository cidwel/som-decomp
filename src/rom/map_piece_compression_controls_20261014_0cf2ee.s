.setcpu "65816"
.segment "CODE"
.org $F2EE
map_control_0cf2ee:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $ED ; backreference distance high bits
    .byte $88 ; distance low bit/count
