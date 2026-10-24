.setcpu "65816"
.segment "CODE"
.org $E2BA
map_control_0de2ba:
    .byte $E0 ; previous-row copy escape
    .byte $13 ; row-distance/count
