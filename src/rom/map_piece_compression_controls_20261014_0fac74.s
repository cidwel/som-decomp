.setcpu "65816"
.segment "CODE"
.org $AC74
map_control_0fac74:
    .byte $C7 ; same-value copy count/distance
    .byte $E5 ; previous-row copy count
