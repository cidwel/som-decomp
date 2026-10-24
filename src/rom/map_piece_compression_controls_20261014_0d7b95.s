.setcpu "65816"
.segment "CODE"
.org $7B95
map_control_0d7b95:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
