.setcpu "65816"
.segment "CODE"
.org $CDE0
map_control_0fcde0:
    .byte $E1 ; previous-row copy count
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
