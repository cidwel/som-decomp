.setcpu "65816"
.segment "CODE"
.org $7023
map_control_0c7023:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
