.setcpu "65816"
.segment "CODE"
.org $0DBF
map_control_0f0dbf:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
