.setcpu "65816"
.segment "CODE"
.org $76AD
map_control_0d76ad:
    .byte $E0 ; previous-row copy escape
    .byte $2A ; row-distance/count
