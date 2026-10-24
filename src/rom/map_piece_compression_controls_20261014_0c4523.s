.setcpu "65816"
.segment "CODE"
.org $4523
map_control_0c4523:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
