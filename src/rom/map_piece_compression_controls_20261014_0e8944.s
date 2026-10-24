.setcpu "65816"
.segment "CODE"
.org $8944
map_control_0e8944:
    .byte $E0 ; previous-row copy escape
    .byte $1F ; row-distance/count
