.setcpu "65816"
.segment "CODE"
.org $AB41
map_control_0fab41:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
