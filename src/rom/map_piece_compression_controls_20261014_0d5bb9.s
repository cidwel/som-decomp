.setcpu "65816"
.segment "CODE"
.org $5BB9
map_control_0d5bb9:
    .byte $C2 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
