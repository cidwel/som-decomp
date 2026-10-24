.setcpu "65816"
.segment "CODE"
.org $7B45
map_control_0e7b45:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
