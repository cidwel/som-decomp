.setcpu "65816"
.segment "CODE"
.org $5A1A
map_control_0e5a1a:
    .byte $E0 ; previous-row copy escape
    .byte $A8 ; row-distance/count
