.setcpu "65816"
.segment "CODE"
.org $302F
map_control_0c302f:
    .byte $E0 ; previous-row copy escape
    .byte $89 ; row-distance/count
