.setcpu "65816"
.segment "CODE"
.org $88A5
map_control_0c88a5:
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
