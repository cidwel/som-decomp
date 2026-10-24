.setcpu "65816"
.segment "CODE"
.org $5D66
map_control_0d5d66:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
    .byte $CB ; same-value copy count/distance
