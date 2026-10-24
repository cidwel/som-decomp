.setcpu "65816"
.segment "CODE"
.org $7C0D
map_control_0e7c0d:
    .byte $E6 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
