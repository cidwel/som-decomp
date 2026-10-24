.setcpu "65816"
.segment "CODE"
.org $4456
map_control_0d4456:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
