.setcpu "65816"
.segment "CODE"
.org $56AE
map_control_0d56ae:
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
