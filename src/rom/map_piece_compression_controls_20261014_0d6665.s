.setcpu "65816"
.segment "CODE"
.org $6665
map_control_0d6665:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
