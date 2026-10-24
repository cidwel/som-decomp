.setcpu "65816"
.segment "CODE"
.org $23C2
map_control_0e23c2:
    .byte $F1 ; progressive-copy count
    .byte $DE ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
