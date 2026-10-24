.setcpu "65816"
.segment "CODE"
.org $D232
map_control_0fd232:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
