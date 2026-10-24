.setcpu "65816"
.segment "CODE"
.org $488D
map_control_0e488d:
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
