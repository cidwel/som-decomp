.setcpu "65816"
.segment "CODE"
.org $74C7
map_control_0d74c7:
    .byte $F1 ; progressive-copy count
    .byte $D9 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
