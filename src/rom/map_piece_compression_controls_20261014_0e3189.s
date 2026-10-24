.setcpu "65816"
.segment "CODE"
.org $3189
map_control_0e3189:
    .byte $E1 ; previous-row copy count
    .byte $C3 ; same-value copy count/distance
