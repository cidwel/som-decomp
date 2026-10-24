.setcpu "65816"
.segment "CODE"
.org $AB96
map_control_0fab96:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $95 ; row-distance/count
