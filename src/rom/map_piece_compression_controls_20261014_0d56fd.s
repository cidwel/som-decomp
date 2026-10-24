.setcpu "65816"
.segment "CODE"
.org $56FD
map_control_0d56fd:
    .byte $C5 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
    .byte $F1 ; progressive-copy count
