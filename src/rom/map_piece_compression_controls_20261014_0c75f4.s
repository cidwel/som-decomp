.setcpu "65816"
.segment "CODE"
.org $75F4
map_control_0c75f4:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
