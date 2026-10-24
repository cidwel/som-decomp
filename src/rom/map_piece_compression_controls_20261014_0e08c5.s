.setcpu "65816"
.segment "CODE"
.org $08C5
map_control_0e08c5:
    .byte $EB ; backreference distance high bits
    .byte $83 ; distance low bit/count
