.setcpu "65816"
.segment "CODE"
.org $D821
map_control_0fd821:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
