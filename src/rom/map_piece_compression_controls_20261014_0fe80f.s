.setcpu "65816"
.segment "CODE"
.org $E80F
map_control_0fe80f:
    .byte $E8 ; backreference distance high bits
    .byte $25 ; distance low bit/count
