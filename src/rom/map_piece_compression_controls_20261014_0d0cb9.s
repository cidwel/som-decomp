.setcpu "65816"
.segment "CODE"
.org $0CB9
map_control_0d0cb9:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $83 ; distance low bit/count
