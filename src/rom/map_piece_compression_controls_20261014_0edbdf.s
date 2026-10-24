.setcpu "65816"
.segment "CODE"
.org $DBDF
map_control_0edbdf:
    .byte $EC ; backreference distance high bits
    .byte $84 ; distance low bit/count
