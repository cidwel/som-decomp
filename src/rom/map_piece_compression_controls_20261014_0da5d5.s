.setcpu "65816"
.segment "CODE"
.org $A5D5
map_control_0da5d5:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
