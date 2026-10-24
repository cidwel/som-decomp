.setcpu "65816"
.segment "CODE"
.org $53C9
map_control_0e53c9:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
