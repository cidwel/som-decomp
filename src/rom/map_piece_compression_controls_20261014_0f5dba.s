.setcpu "65816"
.segment "CODE"
.org $5DBA
map_control_0f5dba:
    .byte $E0 ; previous-row copy escape
    .byte $A2 ; row-distance/count
