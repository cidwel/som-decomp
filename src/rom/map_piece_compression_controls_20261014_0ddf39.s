.setcpu "65816"
.segment "CODE"
.org $DF39
map_control_0ddf39:
    .byte $C2 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
