.setcpu "65816"
.segment "CODE"
.org $DB57
map_control_0fdb57:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
