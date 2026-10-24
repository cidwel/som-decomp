.setcpu "65816"
.segment "CODE"
.org $AB78
map_control_0fab78:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
