.setcpu "65816"
.segment "CODE"
.org $BAC2
map_control_0ebac2:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
