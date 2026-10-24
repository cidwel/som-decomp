.setcpu "65816"
.segment "CODE"
.org $E09D
map_control_0fe09d:
    .byte $C2 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $08 ; distance low bit/count
    .byte $E0 ; previous-row copy escape
    .byte $62 ; row-distance/count
