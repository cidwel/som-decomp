.setcpu "65816"
.segment "CODE"
.org $E9F8
map_control_0de9f8:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DC ; same-value copy count/distance
