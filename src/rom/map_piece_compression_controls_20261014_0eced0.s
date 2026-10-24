.setcpu "65816"
.segment "CODE"
.org $CED0
map_control_0eced0:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
