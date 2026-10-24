.setcpu "65816"
.segment "CODE"
.org $A24A
map_control_0da24a:
    .byte $E0 ; previous-row copy escape
    .byte $84 ; row-distance/count
