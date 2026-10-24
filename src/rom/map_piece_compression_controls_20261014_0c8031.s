.setcpu "65816"
.segment "CODE"
.org $8031
map_control_0c8031:
    .byte $EA ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
