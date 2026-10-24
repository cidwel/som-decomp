.setcpu "65816"
.segment "CODE"
.org $25C2
map_control_0e25c2:
    .byte $F1 ; progressive-copy count
    .byte $E2 ; previous-row copy count
    .byte $C5 ; same-value copy count/distance
    .byte $F4 ; progressive-copy count
