.setcpu "65816"
.segment "CODE"
.org $C3BE
map_control_0dc3be:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
