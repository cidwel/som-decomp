.setcpu "65816"
.segment "CODE"
.org $185C
map_control_0d185c:
    .byte $E8 ; backreference distance high bits
    .byte $83 ; distance low bit/count
