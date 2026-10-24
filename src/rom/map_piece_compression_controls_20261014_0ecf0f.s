.setcpu "65816"
.segment "CODE"
.org $CF0F
map_control_0ecf0f:
    .byte $F2 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $C4 ; same-value copy count/distance
