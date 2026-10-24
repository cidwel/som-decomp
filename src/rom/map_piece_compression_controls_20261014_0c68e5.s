.setcpu "65816"
.segment "CODE"
.org $68E5
map_control_0c68e5:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
