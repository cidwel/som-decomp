.setcpu "65816"
.segment "CODE"
.org $F372
map_control_0ef372:
    .byte $C9 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E1 ; previous-row copy count
