.setcpu "65816"
.segment "CODE"
.org $4852
map_control_0e4852:
    .byte $C1 ; same-value copy count/distance
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
