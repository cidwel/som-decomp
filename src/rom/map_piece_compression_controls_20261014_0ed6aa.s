.setcpu "65816"
.segment "CODE"
.org $D6AA
map_control_0ed6aa:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
