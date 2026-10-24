.setcpu "65816"
.segment "CODE"
.org $59E9
map_control_0e59e9:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E4 ; previous-row copy count
