.setcpu "65816"
.segment "CODE"
.org $3ADD
map_control_0e3add:
    .byte $E3 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
