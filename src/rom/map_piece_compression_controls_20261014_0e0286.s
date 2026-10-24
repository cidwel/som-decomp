.setcpu "65816"
.segment "CODE"
.org $0286
map_control_0e0286:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
