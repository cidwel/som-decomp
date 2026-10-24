.setcpu "65816"
.segment "CODE"
.org $302A
map_control_0c302a:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
