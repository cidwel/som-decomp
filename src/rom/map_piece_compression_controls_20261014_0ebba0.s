.setcpu "65816"
.segment "CODE"
.org $BBA0
map_control_0ebba0:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
