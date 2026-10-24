.setcpu "65816"
.segment "CODE"
.org $F492
map_control_0df492:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
