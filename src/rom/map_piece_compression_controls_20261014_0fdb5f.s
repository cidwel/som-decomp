.setcpu "65816"
.segment "CODE"
.org $DB5F
map_control_0fdb5f:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
