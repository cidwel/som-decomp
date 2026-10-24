.setcpu "65816"
.segment "CODE"
.org $C94C
map_control_0dc94c:
    .byte $CD ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
