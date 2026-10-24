.setcpu "65816"
.segment "CODE"
.org $3E32
map_control_0c3e32:
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
