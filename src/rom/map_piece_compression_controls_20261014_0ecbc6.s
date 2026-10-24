.setcpu "65816"
.segment "CODE"
.org $CBC6
map_control_0ecbc6:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
