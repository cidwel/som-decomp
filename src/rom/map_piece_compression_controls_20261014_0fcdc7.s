.setcpu "65816"
.segment "CODE"
.org $CDC7
map_control_0fcdc7:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $EE ; backreference distance high bits
    .byte $04 ; distance low bit/count
    .byte $C9 ; same-value copy count/distance
