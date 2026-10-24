.setcpu "65816"
.segment "CODE"
.org $9466
map_control_0d9466:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
