.setcpu "65816"
.segment "CODE"
.org $DBBA
map_control_0edbba:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
