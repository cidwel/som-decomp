.setcpu "65816"
.segment "CODE"
.org $B8E1
map_control_0fb8e1:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
