.setcpu "65816"
.segment "CODE"
.org $6BD3
map_control_0f6bd3:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
