.setcpu "65816"
.segment "CODE"
.org $12EB
map_control_0d12eb:
    .byte $E9 ; backreference distance high bits
    .byte $83 ; distance low bit/count
