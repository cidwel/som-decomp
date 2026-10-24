.setcpu "65816"
.segment "CODE"
.org $9C39
map_control_0d9c39:
    .byte $E4 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
