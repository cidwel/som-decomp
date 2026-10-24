.setcpu "65816"
.segment "CODE"
.org $8DB0
map_control_0f8db0:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
