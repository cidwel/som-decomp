.setcpu "65816"
.segment "CODE"
.org $C9FA
map_control_0ec9fa:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
