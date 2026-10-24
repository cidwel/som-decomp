.setcpu "65816"
.segment "CODE"
.org $C9EF
map_control_0ec9ef:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
