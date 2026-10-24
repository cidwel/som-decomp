.setcpu "65816"
.segment "CODE"
.org $AA1F
map_control_0faa1f:
    .byte $E4 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
