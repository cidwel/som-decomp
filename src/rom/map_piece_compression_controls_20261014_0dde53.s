.setcpu "65816"
.segment "CODE"
.org $DE53
map_control_0dde53:
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
