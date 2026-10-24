.setcpu "65816"
.segment "CODE"
.org $BFB3
map_control_0dbfb3:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
