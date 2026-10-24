.setcpu "65816"
.segment "CODE"
.org $9EDC
map_control_0d9edc:
    .byte $EE ; backreference distance high bits
    .byte $05 ; distance low bit/count
