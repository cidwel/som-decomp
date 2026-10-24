.setcpu "65816"
.segment "CODE"
.org $1366
map_control_0f1366:
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $29 ; row-distance/count
