.setcpu "65816"
.segment "CODE"
.org $8559
map_control_0d8559:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
