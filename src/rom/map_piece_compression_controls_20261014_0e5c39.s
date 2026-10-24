.setcpu "65816"
.segment "CODE"
.org $5C39
map_control_0e5c39:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
