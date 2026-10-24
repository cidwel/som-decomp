.setcpu "65816"
.segment "CODE"
.org $4692
map_control_0d4692:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
