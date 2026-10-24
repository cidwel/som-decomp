.setcpu "65816"
.segment "CODE"
.org $DDA3
map_control_0ddda3:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
