.setcpu "65816"
.segment "CODE"
.org $812D
map_control_0d812d:
    .byte $CB ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DB ; same-value copy count/distance
