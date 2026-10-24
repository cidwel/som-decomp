.setcpu "65816"
.segment "CODE"
.org $28DB
map_control_0e28db:
    .byte $C3 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
