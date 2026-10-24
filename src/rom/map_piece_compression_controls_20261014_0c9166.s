.setcpu "65816"
.segment "CODE"
.org $9166
map_control_0c9166:
    .byte $E8 ; backreference distance high bits
    .byte $82 ; distance low bit/count
