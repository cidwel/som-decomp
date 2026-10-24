.setcpu "65816"
.segment "CODE"
.org $3190
map_control_0f3190:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $C6 ; same-value copy count/distance
    .byte $E0 ; previous-row copy escape
    .byte $92 ; row-distance/count
