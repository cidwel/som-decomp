.setcpu "65816"
.segment "CODE"
.org $5093
map_control_0c5093:
    .byte $EF ; backreference distance high bits
    .byte $8C ; distance low bit/count
    .byte $EE ; backreference distance high bits
    .byte $84 ; distance low bit/count
    .byte $EF ; backreference distance high bits
    .byte $84 ; distance low bit/count
