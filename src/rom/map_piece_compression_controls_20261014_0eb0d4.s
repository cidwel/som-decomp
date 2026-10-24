.setcpu "65816"
.segment "CODE"
.org $B0D4
map_control_0eb0d4:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
