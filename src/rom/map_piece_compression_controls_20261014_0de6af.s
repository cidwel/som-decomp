.setcpu "65816"
.segment "CODE"
.org $E6AF
map_control_0de6af:
    .byte $E0 ; previous-row copy escape
    .byte $09 ; row-distance/count
