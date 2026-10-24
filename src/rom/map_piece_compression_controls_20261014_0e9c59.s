.setcpu "65816"
.segment "CODE"
.org $9C59
map_control_0e9c59:
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
