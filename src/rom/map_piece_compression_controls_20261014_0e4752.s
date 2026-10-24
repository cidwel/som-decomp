.setcpu "65816"
.segment "CODE"
.org $4752
map_control_0e4752:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EF ; backreference distance high bits
    .byte $8B ; distance low bit/count
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
