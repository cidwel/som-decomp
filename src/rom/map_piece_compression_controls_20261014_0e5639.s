.setcpu "65816"
.segment "CODE"
.org $5639
map_control_0e5639:
    .byte $F2 ; progressive-copy count
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
