.setcpu "65816"
.segment "CODE"
.org $0274
map_control_0e0274:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
