.setcpu "65816"
.segment "CODE"
.org $4ACA
map_control_0c4aca:
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
