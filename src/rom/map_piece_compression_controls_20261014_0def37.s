.setcpu "65816"
.segment "CODE"
.org $EF37
map_control_0def37:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
