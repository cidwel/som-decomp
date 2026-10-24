.setcpu "65816"
.segment "CODE"
.org $3BAF
map_control_0e3baf:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $08 ; distance low bit/count
