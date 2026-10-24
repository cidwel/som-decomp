.setcpu "65816"
.segment "CODE"
.org $E60C
map_control_0de60c:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
