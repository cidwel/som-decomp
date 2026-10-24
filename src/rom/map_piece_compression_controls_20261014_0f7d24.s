.setcpu "65816"
.segment "CODE"
.org $7D24
map_control_0f7d24:
    .byte $E5 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
