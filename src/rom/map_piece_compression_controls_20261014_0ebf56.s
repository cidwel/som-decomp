.setcpu "65816"
.segment "CODE"
.org $BF56
map_control_0ebf56:
    .byte $EE ; backreference distance high bits
    .byte $8C ; distance low bit/count
