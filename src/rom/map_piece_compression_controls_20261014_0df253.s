.setcpu "65816"
.segment "CODE"
.org $F253
map_control_0df253:
    .byte $E0 ; previous-row copy escape
    .byte $9A ; row-distance/count
