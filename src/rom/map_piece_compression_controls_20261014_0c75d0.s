.setcpu "65816"
.segment "CODE"
.org $75D0
map_control_0c75d0:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
