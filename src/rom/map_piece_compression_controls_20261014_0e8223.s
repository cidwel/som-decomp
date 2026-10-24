.setcpu "65816"
.segment "CODE"
.org $8223
map_control_0e8223:
    .byte $E1 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
