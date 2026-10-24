.setcpu "65816"
.segment "CODE"
.org $9ECA
map_control_0d9eca:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
