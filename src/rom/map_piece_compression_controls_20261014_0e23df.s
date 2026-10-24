.setcpu "65816"
.segment "CODE"
.org $23DF
map_control_0e23df:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $C2 ; same-value copy count/distance
    .byte $E1 ; previous-row copy count
