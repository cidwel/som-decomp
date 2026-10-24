.setcpu "65816"
.segment "CODE"
.org $37CF
map_control_0d37cf:
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
