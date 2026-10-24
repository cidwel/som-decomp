.setcpu "65816"
.segment "CODE"
.org $D86C
map_control_0fd86c:
    .byte $C6 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
