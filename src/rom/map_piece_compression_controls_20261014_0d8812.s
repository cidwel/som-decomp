.setcpu "65816"
.segment "CODE"
.org $8812
map_control_0d8812:
    .byte $E0 ; previous-row copy escape
    .byte $8F ; row-distance/count
