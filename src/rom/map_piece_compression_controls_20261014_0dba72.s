.setcpu "65816"
.segment "CODE"
.org $BA72
map_control_0dba72:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
