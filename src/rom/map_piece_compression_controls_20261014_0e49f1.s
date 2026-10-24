.setcpu "65816"
.segment "CODE"
.org $49F1
map_control_0e49f1:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
