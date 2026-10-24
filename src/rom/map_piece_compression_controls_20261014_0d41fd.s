.setcpu "65816"
.segment "CODE"
.org $41FD
map_control_0d41fd:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
