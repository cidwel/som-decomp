.setcpu "65816"
.segment "CODE"
.org $7B44
map_control_0f7b44:
    .byte $E3 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
