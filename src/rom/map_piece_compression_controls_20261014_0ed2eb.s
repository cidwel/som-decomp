.setcpu "65816"
.segment "CODE"
.org $D2EB
map_control_0ed2eb:
    .byte $C2 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $82 ; distance low bit/count
