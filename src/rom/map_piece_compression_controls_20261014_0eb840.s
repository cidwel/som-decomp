.setcpu "65816"
.segment "CODE"
.org $B840
map_control_0eb840:
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
