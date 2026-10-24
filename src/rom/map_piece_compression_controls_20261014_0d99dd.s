.setcpu "65816"
.segment "CODE"
.org $99DD
map_control_0d99dd:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
