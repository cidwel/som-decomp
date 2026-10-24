.setcpu "65816"
.segment "CODE"
.org $6C27
map_control_0c6c27:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
