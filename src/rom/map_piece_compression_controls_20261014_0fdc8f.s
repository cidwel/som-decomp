.setcpu "65816"
.segment "CODE"
.org $DC8F
map_control_0fdc8f:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
    .byte $DB ; same-value copy count/distance
