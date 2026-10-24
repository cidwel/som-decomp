.setcpu "65816"
.segment "CODE"
.org $CD53
map_control_0dcd53:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
