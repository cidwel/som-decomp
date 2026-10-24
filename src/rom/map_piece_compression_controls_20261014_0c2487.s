.setcpu "65816"
.segment "CODE"
.org $2487
map_control_0c2487:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
