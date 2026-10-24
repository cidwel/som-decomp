.setcpu "65816"
.segment "CODE"
.org $CAA9
map_control_0ecaa9:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
