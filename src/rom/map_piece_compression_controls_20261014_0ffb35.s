.setcpu "65816"
.segment "CODE"
.org $FB35
map_control_0ffb35:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
