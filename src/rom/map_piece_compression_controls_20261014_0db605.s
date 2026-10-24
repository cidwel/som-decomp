.setcpu "65816"
.segment "CODE"
.org $B605
map_control_0db605:
    .byte $C2 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
