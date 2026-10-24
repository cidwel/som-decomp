.setcpu "65816"
.segment "CODE"
.org $68EC
map_control_0c68ec:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
