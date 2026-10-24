.setcpu "65816"
.segment "CODE"
.org $DB2D
map_control_0ddb2d:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
