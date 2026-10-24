.setcpu "65816"
.segment "CODE"
.org $2BE7
map_control_0d2be7:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
