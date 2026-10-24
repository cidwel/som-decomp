.setcpu "65816"
.segment "CODE"
.org $9833
map_control_0e9833:
    .byte $E8 ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $EA ; backreference distance high bits
    .byte $04 ; distance low bit/count
