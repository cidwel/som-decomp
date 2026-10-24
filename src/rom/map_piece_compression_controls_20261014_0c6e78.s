.setcpu "65816"
.segment "CODE"
.org $6E78
map_control_0c6e78:
    .byte $C9 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
