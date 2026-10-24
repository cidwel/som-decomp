.setcpu "65816"
.segment "CODE"
.org $5D63
map_control_0c5d63:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
