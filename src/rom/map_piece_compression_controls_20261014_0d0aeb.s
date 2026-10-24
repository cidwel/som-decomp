.setcpu "65816"
.segment "CODE"
.org $0AEB
map_control_0d0aeb:
    .byte $EB ; backreference distance high bits
    .byte $03 ; distance low bit/count
