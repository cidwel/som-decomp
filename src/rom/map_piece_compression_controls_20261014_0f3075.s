.setcpu "65816"
.segment "CODE"
.org $3075
map_control_0f3075:
    .byte $E7 ; previous-row copy count
    .byte $C7 ; same-value copy count/distance
