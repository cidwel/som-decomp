.setcpu "65816"
.segment "CODE"
.org $368D
map_control_0d368d:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
