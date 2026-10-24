.setcpu "65816"
.segment "CODE"
.org $9067
map_control_0c9067:
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
