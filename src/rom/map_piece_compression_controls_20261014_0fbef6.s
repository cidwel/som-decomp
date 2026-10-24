.setcpu "65816"
.segment "CODE"
.org $BEF6
map_control_0fbef6:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
