.setcpu "65816"
.segment "CODE"
.org $6B0E
map_control_0e6b0e:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
