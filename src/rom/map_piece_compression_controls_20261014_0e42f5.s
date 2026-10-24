.setcpu "65816"
.segment "CODE"
.org $42F5
map_control_0e42f5:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
