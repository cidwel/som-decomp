.setcpu "65816"
.segment "CODE"
.org $863C
map_control_0e863c:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
