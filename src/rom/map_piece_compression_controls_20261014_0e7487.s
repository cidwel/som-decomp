.setcpu "65816"
.segment "CODE"
.org $7487
map_control_0e7487:
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
