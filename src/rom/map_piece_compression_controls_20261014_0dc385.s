.setcpu "65816"
.segment "CODE"
.org $C385
map_control_0dc385:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
