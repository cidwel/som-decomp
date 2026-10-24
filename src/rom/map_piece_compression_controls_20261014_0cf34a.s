.setcpu "65816"
.segment "CODE"
.org $F34A
map_control_0cf34a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
