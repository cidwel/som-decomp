.setcpu "65816"
.segment "CODE"
.org $8095
map_control_0d8095:
    .byte $D1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
