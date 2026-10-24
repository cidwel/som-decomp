.setcpu "65816"
.segment "CODE"
.org $DE21
map_control_0dde21:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
