.setcpu "65816"
.segment "CODE"
.org $58FD
map_control_0c58fd:
    .byte $ED ; backreference distance high bits
    .byte $82 ; distance low bit/count
