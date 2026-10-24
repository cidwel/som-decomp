.setcpu "65816"
.segment "CODE"
.org $247D
map_control_0f247d:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
