.setcpu "65816"
.segment "CODE"
.org $487C
map_control_0e487c:
    .byte $F1 ; progressive-copy count
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $EB ; backreference distance high bits
    .byte $87 ; distance low bit/count
    .byte $E7 ; previous-row copy count
