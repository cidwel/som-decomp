.setcpu "65816"
.segment "CODE"
.org $CB08
map_control_0dcb08:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
