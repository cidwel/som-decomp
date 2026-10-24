.setcpu "65816"
.segment "CODE"
.org $7D18
map_control_0f7d18:
    .byte $E7 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
