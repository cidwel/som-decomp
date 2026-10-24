.setcpu "65816"
.segment "CODE"
.org $77C0
map_control_0d77c0:
    .byte $E2 ; previous-row copy count
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $38 ; row-distance/count
