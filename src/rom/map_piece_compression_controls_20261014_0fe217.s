.setcpu "65816"
.segment "CODE"
.org $E217
map_control_0fe217:
    .byte $E0 ; previous-row copy escape
    .byte $54 ; row-distance/count
