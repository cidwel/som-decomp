.setcpu "65816"
.segment "CODE"
.org $2157
map_control_0e2157:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C6 ; same-value copy count/distance
