.setcpu "65816"
.segment "CODE"
.org $6BB4
map_control_0e6bb4:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
