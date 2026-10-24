.setcpu "65816"
.segment "CODE"
.org $6C16
map_control_0c6c16:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
