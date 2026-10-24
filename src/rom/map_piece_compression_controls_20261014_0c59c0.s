.setcpu "65816"
.segment "CODE"
.org $59C0
map_control_0c59c0:
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $85 ; distance low bit/count
