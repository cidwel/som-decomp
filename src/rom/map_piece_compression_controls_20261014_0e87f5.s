.setcpu "65816"
.segment "CODE"
.org $87F5
map_control_0e87f5:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
