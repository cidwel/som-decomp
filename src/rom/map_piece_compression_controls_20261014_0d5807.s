.setcpu "65816"
.segment "CODE"
.org $5807
map_control_0d5807:
    .byte $EB ; backreference distance high bits
    .byte $06 ; distance low bit/count
