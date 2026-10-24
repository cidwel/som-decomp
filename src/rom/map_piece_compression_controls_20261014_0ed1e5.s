.setcpu "65816"
.segment "CODE"
.org $D1E5
map_control_0ed1e5:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
