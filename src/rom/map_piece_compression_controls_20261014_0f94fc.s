.setcpu "65816"
.segment "CODE"
.org $94FC
map_control_0f94fc:
    .byte $EE ; backreference distance high bits
    .byte $89 ; distance low bit/count
