.setcpu "65816"
.segment "CODE"
.org $E97C
map_control_0de97c:
    .byte $C7 ; same-value copy count/distance
    .byte $E6 ; previous-row copy count
