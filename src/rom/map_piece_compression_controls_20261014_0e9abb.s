.setcpu "65816"
.segment "CODE"
.org $9ABB
map_control_0e9abb:
    .byte $DB ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
