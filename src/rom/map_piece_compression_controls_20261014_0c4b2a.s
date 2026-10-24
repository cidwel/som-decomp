.setcpu "65816"
.segment "CODE"
.org $4B2A
map_control_0c4b2a:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
