.setcpu "65816"
.segment "CODE"
.org $7765
map_control_0e7765:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
