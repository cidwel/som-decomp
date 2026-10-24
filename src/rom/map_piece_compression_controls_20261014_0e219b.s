.setcpu "65816"
.segment "CODE"
.org $219B
map_control_0e219b:
    .byte $E9 ; backreference distance high bits
    .byte $03 ; distance low bit/count
