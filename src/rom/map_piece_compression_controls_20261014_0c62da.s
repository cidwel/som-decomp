.setcpu "65816"
.segment "CODE"
.org $62DA
map_control_0c62da:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
