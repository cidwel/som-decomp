.setcpu "65816"
.segment "CODE"
.org $7901
map_control_0c7901:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
