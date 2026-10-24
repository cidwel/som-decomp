.setcpu "65816"
.segment "CODE"
.org $51A1
map_control_0d51a1:
    .byte $DB ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DC ; same-value copy count/distance
