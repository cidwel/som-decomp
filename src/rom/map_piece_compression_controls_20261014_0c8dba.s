.setcpu "65816"
.segment "CODE"
.org $8DBA
map_control_0c8dba:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $C1 ; same-value copy count/distance
