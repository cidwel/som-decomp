.setcpu "65816"
.segment "CODE"
.org $C329
map_control_0dc329:
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
