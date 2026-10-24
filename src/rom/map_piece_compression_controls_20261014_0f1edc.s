.setcpu "65816"
.segment "CODE"
.org $1EDC
map_control_0f1edc:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
