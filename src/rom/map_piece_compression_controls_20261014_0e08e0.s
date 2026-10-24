.setcpu "65816"
.segment "CODE"
.org $08E0
map_control_0e08e0:
    .byte $E5 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
