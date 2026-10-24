.setcpu "65816"
.segment "CODE"
.org $167F
map_control_0f167f:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
