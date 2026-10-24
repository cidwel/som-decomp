.setcpu "65816"
.segment "CODE"
.org $6E38
map_control_0e6e38:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
