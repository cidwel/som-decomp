.setcpu "65816"
.segment "CODE"
.org $DADF
map_control_0edadf:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
