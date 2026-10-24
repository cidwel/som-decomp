.setcpu "65816"
.segment "CODE"
.org $D91A
map_control_0ed91a:
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D3 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
