.setcpu "65816"
.segment "CODE"
.org $4886
map_control_0e4886:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E5 ; previous-row copy count
