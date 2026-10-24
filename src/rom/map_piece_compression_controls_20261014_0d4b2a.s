.setcpu "65816"
.segment "CODE"
.org $4B2A
map_control_0d4b2a:
    .byte $C6 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
