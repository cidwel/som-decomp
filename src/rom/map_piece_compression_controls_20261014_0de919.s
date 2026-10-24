.setcpu "65816"
.segment "CODE"
.org $E919
map_control_0de919:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $2E ; row-distance/count
