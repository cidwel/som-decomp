.setcpu "65816"
.segment "CODE"
.org $7BFD
map_control_0e7bfd:
    .byte $E6 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
