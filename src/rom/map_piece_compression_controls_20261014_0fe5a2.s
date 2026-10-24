.setcpu "65816"
.segment "CODE"
.org $E5A2
map_control_0fe5a2:
    .byte $E2 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
