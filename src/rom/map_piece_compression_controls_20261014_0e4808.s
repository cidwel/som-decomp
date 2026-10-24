.setcpu "65816"
.segment "CODE"
.org $4808
map_control_0e4808:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EE ; backreference distance high bits
    .byte $87 ; distance low bit/count
