.setcpu "65816"
.segment "CODE"
.org $DFC9
map_control_0ddfc9:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
