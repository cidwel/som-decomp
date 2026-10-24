.setcpu "65816"
.segment "CODE"
.org $28EF
map_control_0e28ef:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
