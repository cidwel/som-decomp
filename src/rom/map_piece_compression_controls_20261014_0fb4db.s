.setcpu "65816"
.segment "CODE"
.org $B4DB
map_control_0fb4db:
    .byte $E0 ; previous-row copy escape
    .byte $50 ; row-distance/count
