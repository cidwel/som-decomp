.setcpu "65816"
.segment "CODE"
.org $5F28
map_control_0e5f28:
    .byte $E1 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
