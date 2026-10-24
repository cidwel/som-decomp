.setcpu "65816"
.segment "CODE"
.org $B7C6
map_control_0fb7c6:
    .byte $E0 ; previous-row copy escape
    .byte $32 ; row-distance/count
    .byte $C7 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
