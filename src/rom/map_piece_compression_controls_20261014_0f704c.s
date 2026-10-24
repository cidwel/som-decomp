.setcpu "65816"
.segment "CODE"
.org $704C
map_control_0f704c:
    .byte $E2 ; previous-row copy count
    .byte $DB ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
