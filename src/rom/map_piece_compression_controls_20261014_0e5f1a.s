.setcpu "65816"
.segment "CODE"
.org $5F1A
map_control_0e5f1a:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
