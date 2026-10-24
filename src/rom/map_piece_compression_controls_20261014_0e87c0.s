.setcpu "65816"
.segment "CODE"
.org $87C0
map_control_0e87c0:
    .byte $E0 ; previous-row copy escape
    .byte $86 ; row-distance/count
