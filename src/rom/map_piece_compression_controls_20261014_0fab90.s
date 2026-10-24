.setcpu "65816"
.segment "CODE"
.org $AB90
map_control_0fab90:
    .byte $E0 ; previous-row copy escape
    .byte $A5 ; row-distance/count
