.setcpu "65816"
.segment "CODE"
.org $449C
map_control_0e449c:
    .byte $E5 ; previous-row copy count
    .byte $C2 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C2 ; same-value copy count/distance
