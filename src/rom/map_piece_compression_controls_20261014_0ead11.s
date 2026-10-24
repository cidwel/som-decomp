.setcpu "65816"
.segment "CODE"
.org $AD11
map_control_0ead11:
    .byte $E0 ; previous-row copy escape
    .byte $15 ; row-distance/count
