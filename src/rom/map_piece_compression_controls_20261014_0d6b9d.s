.setcpu "65816"
.segment "CODE"
.org $6B9D
map_control_0d6b9d:
    .byte $C1 ; same-value copy count/distance
    .byte $E3 ; previous-row copy count
