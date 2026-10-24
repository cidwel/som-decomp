.setcpu "65816"
.segment "CODE"
.org $B075
map_control_0eb075:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
