.setcpu "65816"
.segment "CODE"
.org $F35B
map_control_0ef35b:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
