.setcpu "65816"
.segment "CODE"
.org $64C5
map_control_0d64c5:
    .byte $E0 ; previous-row copy escape
    .byte $19 ; row-distance/count
