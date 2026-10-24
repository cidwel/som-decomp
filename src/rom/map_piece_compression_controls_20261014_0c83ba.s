.setcpu "65816"
.segment "CODE"
.org $83BA
map_control_0c83ba:
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
