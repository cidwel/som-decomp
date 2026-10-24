.setcpu "65816"
.segment "CODE"
.org $6079
map_control_0c6079:
    .byte $EE ; backreference distance high bits
    .byte $83 ; distance low bit/count
