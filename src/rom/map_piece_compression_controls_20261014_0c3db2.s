.setcpu "65816"
.segment "CODE"
.org $3DB2
map_control_0c3db2:
    .byte $D5 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
