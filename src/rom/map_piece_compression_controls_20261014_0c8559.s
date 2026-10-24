.setcpu "65816"
.segment "CODE"
.org $8559
map_control_0c8559:
    .byte $E0 ; previous-row copy escape
    .byte $3F ; row-distance/count
