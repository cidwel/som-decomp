.setcpu "65816"
.segment "CODE"
.org $D2DB
map_control_0fd2db:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
