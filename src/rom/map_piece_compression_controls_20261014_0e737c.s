.setcpu "65816"
.segment "CODE"
.org $737C
map_control_0e737c:
    .byte $E0 ; previous-row copy escape
    .byte $17 ; row-distance/count
