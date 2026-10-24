.setcpu "65816"
.segment "CODE"
.org $A1E8
map_control_0da1e8:
    .byte $E0 ; previous-row copy escape
    .byte $87 ; row-distance/count
