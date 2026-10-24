.setcpu "65816"
.segment "CODE"
.org $5925
map_control_0d5925:
    .byte $EB ; backreference distance high bits
    .byte $86 ; distance low bit/count
