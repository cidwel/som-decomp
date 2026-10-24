.setcpu "65816"
.segment "CODE"
.org $D2CC
map_control_0ed2cc:
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $06 ; distance low bit/count
