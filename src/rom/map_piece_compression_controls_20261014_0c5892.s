.setcpu "65816"
.segment "CODE"
.org $5892
map_control_0c5892:
    .byte $EF ; backreference distance high bits
    .byte $89 ; distance low bit/count
