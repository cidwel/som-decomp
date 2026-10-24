.setcpu "65816"
.segment "CODE"
.org $B801
map_control_0db801:
    .byte $C3 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
