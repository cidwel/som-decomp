.setcpu "65816"
.segment "CODE"
.org $2013
map_control_0e2013:
    .byte $E4 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
