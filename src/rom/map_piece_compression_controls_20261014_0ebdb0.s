.setcpu "65816"
.segment "CODE"
.org $BDB0
map_control_0ebdb0:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
