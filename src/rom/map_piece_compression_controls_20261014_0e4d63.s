.setcpu "65816"
.segment "CODE"
.org $4D63
map_control_0e4d63:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
