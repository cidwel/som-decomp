.setcpu "65816"
.segment "CODE"
.org $2A60
map_control_0e2a60:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
