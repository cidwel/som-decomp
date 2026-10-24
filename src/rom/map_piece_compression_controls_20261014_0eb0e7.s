.setcpu "65816"
.segment "CODE"
.org $B0E7
map_control_0eb0e7:
    .byte $DB ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
