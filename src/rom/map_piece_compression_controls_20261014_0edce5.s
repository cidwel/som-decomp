.setcpu "65816"
.segment "CODE"
.org $DCE5
map_control_0edce5:
    .byte $E8 ; backreference distance high bits
    .byte $0C ; distance low bit/count
