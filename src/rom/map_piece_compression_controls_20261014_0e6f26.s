.setcpu "65816"
.segment "CODE"
.org $6F26
map_control_0e6f26:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
