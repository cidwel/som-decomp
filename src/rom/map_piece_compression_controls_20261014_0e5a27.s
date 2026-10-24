.setcpu "65816"
.segment "CODE"
.org $5A27
map_control_0e5a27:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
