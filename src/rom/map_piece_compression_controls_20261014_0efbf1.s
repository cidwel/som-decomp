.setcpu "65816"
.segment "CODE"
.org $FBF1
map_control_0efbf1:
    .byte $EF ; backreference distance high bits
    .byte $82 ; distance low bit/count
