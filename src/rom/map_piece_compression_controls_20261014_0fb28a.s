.setcpu "65816"
.segment "CODE"
.org $B28A
map_control_0fb28a:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
