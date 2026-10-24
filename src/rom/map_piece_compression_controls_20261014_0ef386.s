.setcpu "65816"
.segment "CODE"
.org $F386
map_control_0ef386:
    .byte $E8 ; backreference distance high bits
    .byte $09 ; distance low bit/count
