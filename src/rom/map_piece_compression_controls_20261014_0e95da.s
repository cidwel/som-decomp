.setcpu "65816"
.segment "CODE"
.org $95DA
map_control_0e95da:
    .byte $EF ; backreference distance high bits
    .byte $0C ; distance low bit/count
