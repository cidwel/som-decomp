.setcpu "65816"
.segment "CODE"
.org $2A5D
map_control_0c2a5d:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
