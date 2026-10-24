.setcpu "65816"
.segment "CODE"
.org $3856
map_control_0e3856:
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $D2 ; same-value copy count/distance
