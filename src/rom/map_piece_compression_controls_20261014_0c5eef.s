.setcpu "65816"
.segment "CODE"
.org $5EEF
map_control_0c5eef:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
