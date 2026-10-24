.setcpu "65816"
.segment "CODE"
.org $ACB9
map_control_0facb9:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
