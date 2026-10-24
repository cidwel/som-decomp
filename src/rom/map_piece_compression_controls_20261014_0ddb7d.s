.setcpu "65816"
.segment "CODE"
.org $DB7D
map_control_0ddb7d:
    .byte $C6 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
