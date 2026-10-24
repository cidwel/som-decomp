.setcpu "65816"
.segment "CODE"
.org $0EF6
map_control_0f0ef6:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
