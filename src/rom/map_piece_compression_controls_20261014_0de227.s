.setcpu "65816"
.segment "CODE"
.org $E227
map_control_0de227:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
