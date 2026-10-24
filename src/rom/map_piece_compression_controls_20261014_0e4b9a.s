.setcpu "65816"
.segment "CODE"
.org $4B9A
map_control_0e4b9a:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
