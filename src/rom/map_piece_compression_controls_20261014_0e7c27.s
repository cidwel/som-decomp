.setcpu "65816"
.segment "CODE"
.org $7C27
map_control_0e7c27:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
