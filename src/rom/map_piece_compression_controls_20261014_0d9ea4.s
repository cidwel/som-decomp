.setcpu "65816"
.segment "CODE"
.org $9EA4
map_control_0d9ea4:
    .byte $E8 ; backreference distance high bits
    .byte $85 ; distance low bit/count
