.setcpu "65816"
.segment "CODE"
.org $077C
map_control_0f077c:
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
