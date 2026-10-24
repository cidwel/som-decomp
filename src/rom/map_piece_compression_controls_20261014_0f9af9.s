.setcpu "65816"
.segment "CODE"
.org $9AF9
map_control_0f9af9:
    .byte $C1 ; same-value copy count/distance
    .byte $E4 ; previous-row copy count
