.setcpu "65816"
.segment "CODE"
.org $8657
map_control_0c8657:
    .byte $E8 ; backreference distance high bits
    .byte $2E ; distance low bit/count
