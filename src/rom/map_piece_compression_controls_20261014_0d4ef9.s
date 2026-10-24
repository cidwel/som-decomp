.setcpu "65816"
.segment "CODE"
.org $4EF9
map_control_0d4ef9:
    .byte $EA ; backreference distance high bits
    .byte $85 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $97 ; distance low bit/count
