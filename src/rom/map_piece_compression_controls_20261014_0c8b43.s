.setcpu "65816"
.segment "CODE"
.org $8B43
map_control_0c8b43:
    .byte $E0 ; previous-row copy escape
    .byte $16 ; row-distance/count
