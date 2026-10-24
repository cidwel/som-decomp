.setcpu "65816"
.segment "CODE"
.org $C401
map_control_0dc401:
    .byte $E0 ; previous-row copy escape
    .byte $20 ; row-distance/count
