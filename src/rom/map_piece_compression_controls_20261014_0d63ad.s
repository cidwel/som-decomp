.setcpu "65816"
.segment "CODE"
.org $63AD
map_control_0d63ad:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
