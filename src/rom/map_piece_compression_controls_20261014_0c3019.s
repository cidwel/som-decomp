.setcpu "65816"
.segment "CODE"
.org $3019
map_control_0c3019:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
