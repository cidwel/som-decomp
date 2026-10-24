.setcpu "65816"
.segment "CODE"
.org $D58C
map_control_0fd58c:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
