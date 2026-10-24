.setcpu "65816"
.segment "CODE"
.org $200C
map_control_0e200c:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
