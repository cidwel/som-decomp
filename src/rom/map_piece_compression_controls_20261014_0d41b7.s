.setcpu "65816"
.segment "CODE"
.org $41B7
map_control_0d41b7:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
