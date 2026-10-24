.setcpu "65816"
.segment "CODE"
.org $3F0C
map_control_0e3f0c:
    .byte $F1 ; progressive-copy count
    .byte $E3 ; previous-row copy count
    .byte $C1 ; same-value copy count/distance
