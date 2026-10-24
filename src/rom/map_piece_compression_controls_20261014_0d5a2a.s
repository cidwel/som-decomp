.setcpu "65816"
.segment "CODE"
.org $5A2A
map_control_0d5a2a:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
