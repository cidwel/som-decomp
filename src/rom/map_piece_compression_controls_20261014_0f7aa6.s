.setcpu "65816"
.segment "CODE"
.org $7AA6
map_control_0f7aa6:
    .byte $C6 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
