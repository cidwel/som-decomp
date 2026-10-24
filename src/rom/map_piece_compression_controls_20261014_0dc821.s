.setcpu "65816"
.segment "CODE"
.org $C821
map_control_0dc821:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
