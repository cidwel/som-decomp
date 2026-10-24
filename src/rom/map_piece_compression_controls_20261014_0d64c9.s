.setcpu "65816"
.segment "CODE"
.org $64C9
map_control_0d64c9:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
