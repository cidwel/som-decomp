.setcpu "65816"
.segment "CODE"
.org $2ADD
map_control_0c2add:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
