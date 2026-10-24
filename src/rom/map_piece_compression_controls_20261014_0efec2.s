.setcpu "65816"
.segment "CODE"
.org $FEC2
map_control_0efec2:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
