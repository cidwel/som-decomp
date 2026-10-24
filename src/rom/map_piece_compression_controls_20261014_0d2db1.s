.setcpu "65816"
.segment "CODE"
.org $2DB1
map_control_0d2db1:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
