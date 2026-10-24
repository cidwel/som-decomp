.setcpu "65816"
.segment "CODE"
.org $7C10
map_control_0c7c10:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
