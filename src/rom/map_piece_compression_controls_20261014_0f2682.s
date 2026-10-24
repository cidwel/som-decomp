.setcpu "65816"
.segment "CODE"
.org $2682
map_control_0f2682:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C4 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
