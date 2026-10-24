.setcpu "65816"
.segment "CODE"
.org $CC76
map_control_0ecc76:
    .byte $C1 ; same-value copy count/distance
    .byte $E7 ; previous-row copy count
