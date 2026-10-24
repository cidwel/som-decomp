.setcpu "65816"
.segment "CODE"
.org $915C
map_control_0c915c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
