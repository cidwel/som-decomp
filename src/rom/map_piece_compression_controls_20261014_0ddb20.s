.setcpu "65816"
.segment "CODE"
.org $DB20
map_control_0ddb20:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
