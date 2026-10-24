.setcpu "65816"
.segment "CODE"
.org $A46C
map_control_0ea46c:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
