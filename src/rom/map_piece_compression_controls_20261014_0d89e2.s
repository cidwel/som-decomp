.setcpu "65816"
.segment "CODE"
.org $89E2
map_control_0d89e2:
    .byte $C5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
