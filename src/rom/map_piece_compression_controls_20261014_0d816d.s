.setcpu "65816"
.segment "CODE"
.org $816D
map_control_0d816d:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
