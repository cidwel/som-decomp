.setcpu "65816"
.segment "CODE"
.org $C298
map_control_0ec298:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
