.setcpu "65816"
.segment "CODE"
.org $41D9
map_control_0c41d9:
    .byte $EF ; backreference distance high bits
    .byte $97 ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
