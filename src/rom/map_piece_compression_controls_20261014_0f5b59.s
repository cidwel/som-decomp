.setcpu "65816"
.segment "CODE"
.org $5B59
map_control_0f5b59:
    .byte $EB ; backreference distance high bits
    .byte $84 ; distance low bit/count
