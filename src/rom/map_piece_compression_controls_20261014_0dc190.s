.setcpu "65816"
.segment "CODE"
.org $C190
map_control_0dc190:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
