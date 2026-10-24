.setcpu "65816"
.segment "CODE"
.org $5F2E
map_control_0e5f2e:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
    .byte $C7 ; same-value copy count/distance
