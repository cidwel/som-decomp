.setcpu "65816"
.segment "CODE"
.org $41FD
map_control_0c41fd:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
