.setcpu "65816"
.segment "CODE"
.org $6804
map_control_0c6804:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
