.setcpu "65816"
.segment "CODE"
.org $A780
map_control_0ea780:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
