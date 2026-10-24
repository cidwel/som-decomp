.setcpu "65816"
.segment "CODE"
.org $A365
map_control_0ea365:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
