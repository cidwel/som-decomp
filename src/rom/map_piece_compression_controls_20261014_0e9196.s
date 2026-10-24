.setcpu "65816"
.segment "CODE"
.org $9196
map_control_0e9196:
    .byte $E0 ; previous-row copy escape
    .byte $A4 ; row-distance/count
