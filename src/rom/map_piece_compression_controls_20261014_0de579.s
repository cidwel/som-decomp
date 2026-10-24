.setcpu "65816"
.segment "CODE"
.org $E579
map_control_0de579:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
