.setcpu "65816"
.segment "CODE"
.org $DBAA
map_control_0edbaa:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
