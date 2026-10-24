.setcpu "65816"
.segment "CODE"
.org $7F0A
map_control_0c7f0a:
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
