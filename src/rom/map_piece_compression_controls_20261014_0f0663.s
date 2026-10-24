.setcpu "65816"
.segment "CODE"
.org $0663
map_control_0f0663:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
