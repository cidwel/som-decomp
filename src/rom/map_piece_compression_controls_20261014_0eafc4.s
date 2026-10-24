.setcpu "65816"
.segment "CODE"
.org $AFC4
map_control_0eafc4:
    .byte $E2 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
