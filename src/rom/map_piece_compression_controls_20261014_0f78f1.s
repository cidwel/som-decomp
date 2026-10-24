.setcpu "65816"
.segment "CODE"
.org $78F1
map_control_0f78f1:
    .byte $EB ; backreference distance high bits
    .byte $05 ; distance low bit/count
