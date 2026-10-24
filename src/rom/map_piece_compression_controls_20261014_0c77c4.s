.setcpu "65816"
.segment "CODE"
.org $77C4
map_control_0c77c4:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
