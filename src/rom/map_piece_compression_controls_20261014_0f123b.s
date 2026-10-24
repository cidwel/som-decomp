.setcpu "65816"
.segment "CODE"
.org $123B
map_control_0f123b:
    .byte $EE ; backreference distance high bits
    .byte $82 ; distance low bit/count
