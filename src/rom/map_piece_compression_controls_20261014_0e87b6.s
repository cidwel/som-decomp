.setcpu "65816"
.segment "CODE"
.org $87B6
map_control_0e87b6:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
