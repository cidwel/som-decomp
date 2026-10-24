.setcpu "65816"
.segment "CODE"
.org $0BF4
map_control_0e0bf4:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
