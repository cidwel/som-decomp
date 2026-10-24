.setcpu "65816"
.segment "CODE"
.org $7DF5
map_control_0e7df5:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
