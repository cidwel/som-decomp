.setcpu "65816"
.segment "CODE"
.org $3733
map_control_0f3733:
    .byte $E0 ; previous-row copy escape
    .byte $10 ; row-distance/count
