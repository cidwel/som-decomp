.setcpu "65816"
.segment "CODE"
.org $A999
map_control_0fa999:
    .byte $E0 ; previous-row copy escape
    .byte $1E ; row-distance/count
