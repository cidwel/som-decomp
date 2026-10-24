.setcpu "65816"
.segment "CODE"
.org $3E9D
map_control_0e3e9d:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
    .byte $C1 ; same-value copy count/distance
