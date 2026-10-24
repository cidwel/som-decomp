.setcpu "65816"
.segment "CODE"
.org $6892
map_control_0f6892:
    .byte $C1 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
