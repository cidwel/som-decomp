.setcpu "65816"
.segment "CODE"
.org $AFC3
map_control_0fafc3:
    .byte $EB ; backreference distance high bits
    .byte $85 ; distance low bit/count
