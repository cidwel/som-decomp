.setcpu "65816"
.segment "CODE"
.org $10A8
map_control_0d10a8:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
