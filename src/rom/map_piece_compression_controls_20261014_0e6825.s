.setcpu "65816"
.segment "CODE"
.org $6825
map_control_0e6825:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
