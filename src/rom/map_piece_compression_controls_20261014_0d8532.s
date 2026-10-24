.setcpu "65816"
.segment "CODE"
.org $8532
map_control_0d8532:
    .byte $E8 ; backreference distance high bits
    .byte $32 ; distance low bit/count
