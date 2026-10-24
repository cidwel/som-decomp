.setcpu "65816"
.segment "CODE"
.org $876B
map_control_0f876b:
    .byte $EF ; backreference distance high bits
    .byte $8E ; distance low bit/count
    .byte $E8 ; backreference distance high bits
    .byte $3B ; distance low bit/count
