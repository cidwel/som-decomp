.setcpu "65816"
.segment "CODE"
.org $FAE4
map_control_0ffae4:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
