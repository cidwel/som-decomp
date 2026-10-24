.setcpu "65816"
.segment "CODE"
.org $EDCE
map_control_0dedce:
    .byte $EA ; backreference distance high bits
    .byte $82 ; distance low bit/count
