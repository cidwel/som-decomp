.setcpu "65816"
.segment "CODE"
.org $B669
map_control_0db669:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
