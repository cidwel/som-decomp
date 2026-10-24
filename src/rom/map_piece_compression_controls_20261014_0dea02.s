.setcpu "65816"
.segment "CODE"
.org $EA02
map_control_0dea02:
    .byte $C3 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $DC ; same-value copy count/distance
