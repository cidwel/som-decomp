.setcpu "65816"
.segment "CODE"
.org $0BED
map_control_0e0bed:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
