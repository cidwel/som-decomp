.setcpu "65816"
.segment "CODE"
.org $361B
map_control_0d361b:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
