.setcpu "65816"
.segment "CODE"
.org $B190
map_control_0db190:
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E2 ; previous-row copy count
