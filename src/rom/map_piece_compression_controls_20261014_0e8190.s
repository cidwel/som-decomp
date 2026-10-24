.setcpu "65816"
.segment "CODE"
.org $8190
map_control_0e8190:
    .byte $F1 ; progressive-copy count
    .byte $E0 ; previous-row copy escape
    .byte $81 ; row-distance/count
    .byte $E1 ; previous-row copy count
