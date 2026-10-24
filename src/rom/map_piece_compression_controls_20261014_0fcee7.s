.setcpu "65816"
.segment "CODE"
.org $CEE7
map_control_0fcee7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
