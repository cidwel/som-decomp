.setcpu "65816"
.segment "CODE"
.org $2851
map_control_0e2851:
    .byte $E0 ; previous-row copy escape
    .byte $1A ; row-distance/count
