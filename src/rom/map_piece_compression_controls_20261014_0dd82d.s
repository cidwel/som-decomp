.setcpu "65816"
.segment "CODE"
.org $D82D
map_control_0dd82d:
    .byte $E2 ; previous-row copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
