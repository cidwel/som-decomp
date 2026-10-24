.setcpu "65816"
.segment "CODE"
.org $7CDA
map_control_0e7cda:
    .byte $EE ; backreference distance high bits
    .byte $85 ; distance low bit/count
