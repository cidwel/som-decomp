.setcpu "65816"
.segment "CODE"
.org $84AF
map_control_0e84af:
    .byte $E1 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
