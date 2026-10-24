.setcpu "65816"
.segment "CODE"
.org $714D
map_control_0c714d:
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
    .byte $C2 ; same-value copy count/distance
