.setcpu "65816"
.segment "CODE"
.org $C238
map_control_0dc238:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
