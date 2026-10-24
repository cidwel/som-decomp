.setcpu "65816"
.segment "CODE"
.org $9B6A
map_control_0f9b6a:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
    .byte $DB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
