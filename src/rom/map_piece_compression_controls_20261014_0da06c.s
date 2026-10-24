.setcpu "65816"
.segment "CODE"
.org $A06C
map_control_0da06c:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
