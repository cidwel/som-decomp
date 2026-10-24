.setcpu "65816"
.segment "CODE"
.org $806D
map_control_0e806d:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
