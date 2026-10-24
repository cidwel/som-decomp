.setcpu "65816"
.segment "CODE"
.org $6DD6
map_control_0c6dd6:
    .byte $F1 ; progressive-copy count
    .byte $C5 ; same-value copy count/distance
    .byte $E2 ; previous-row copy count
