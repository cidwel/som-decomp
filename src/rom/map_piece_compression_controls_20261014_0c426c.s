.setcpu "65816"
.segment "CODE"
.org $426C
map_control_0c426c:
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
