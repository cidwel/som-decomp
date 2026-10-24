.setcpu "65816"
.segment "CODE"
.org $B497
map_control_0eb497:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
