.setcpu "65816"
.segment "CODE"
.org $69A1
map_control_0c69a1:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
