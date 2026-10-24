.setcpu "65816"
.segment "CODE"
.org $9AF3
map_control_0d9af3:
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
