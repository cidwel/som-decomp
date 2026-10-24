.setcpu "65816"
.segment "CODE"
.org $457D
map_control_0c457d:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
