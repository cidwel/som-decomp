.setcpu "65816"
.segment "CODE"
.org $4BFF
map_control_0e4bff:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
