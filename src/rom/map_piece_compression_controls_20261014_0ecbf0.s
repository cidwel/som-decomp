.setcpu "65816"
.segment "CODE"
.org $CBF0
map_control_0ecbf0:
    .byte $C3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D7 ; same-value copy count/distance
