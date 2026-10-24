.setcpu "65816"
.segment "CODE"
.org $143F
map_control_0e143f:
    .byte $C1 ; same-value copy count/distance
    .byte $EB ; backreference distance high bits
    .byte $04 ; distance low bit/count
