.setcpu "65816"
.segment "CODE"
.org $F132
map_control_0cf132:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
