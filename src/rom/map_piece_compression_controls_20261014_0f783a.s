.setcpu "65816"
.segment "CODE"
.org $783A
map_control_0f783a:
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
