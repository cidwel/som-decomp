.setcpu "65816"
.segment "CODE"
.org $2E2B
map_control_0f2e2b:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
