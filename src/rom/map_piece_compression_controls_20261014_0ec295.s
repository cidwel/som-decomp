.setcpu "65816"
.segment "CODE"
.org $C295
map_control_0ec295:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
