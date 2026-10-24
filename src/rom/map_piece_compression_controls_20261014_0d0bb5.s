.setcpu "65816"
.segment "CODE"
.org $0BB5
map_control_0d0bb5:
    .byte $E5 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
