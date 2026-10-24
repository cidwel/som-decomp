.setcpu "65816"
.segment "CODE"
.org $E79C
map_control_0de79c:
    .byte $D1 ; same-value copy count/distance
    .byte $D6 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
