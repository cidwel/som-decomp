.setcpu "65816"
.segment "CODE"
.org $491C
map_control_0e491c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
