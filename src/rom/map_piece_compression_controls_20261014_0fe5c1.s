.setcpu "65816"
.segment "CODE"
.org $E5C1
map_control_0fe5c1:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
