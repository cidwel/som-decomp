.setcpu "65816"
.segment "CODE"
.org $CE95
map_control_0ece95:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $8D ; distance low bit/count
