.setcpu "65816"
.segment "CODE"
.org $BB95
map_control_0ebb95:
    .byte $E8 ; backreference distance high bits
    .byte $8B ; distance low bit/count
