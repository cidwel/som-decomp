.setcpu "65816"
.segment "CODE"
.org $7E99
map_control_0c7e99:
    .byte $EE ; backreference distance high bits
    .byte $0A ; distance low bit/count
