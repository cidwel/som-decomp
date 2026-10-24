.setcpu "65816"
.segment "CODE"
.org $BB72
map_control_0ebb72:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
