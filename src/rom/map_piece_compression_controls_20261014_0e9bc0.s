.setcpu "65816"
.segment "CODE"
.org $9BC0
map_control_0e9bc0:
    .byte $C4 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
