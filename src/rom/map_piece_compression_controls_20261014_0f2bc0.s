.setcpu "65816"
.segment "CODE"
.org $2BC0
map_control_0f2bc0:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
