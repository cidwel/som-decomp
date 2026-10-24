.setcpu "65816"
.segment "CODE"
.org $BE59
map_control_0fbe59:
    .byte $E0 ; previous-row copy escape
    .byte $26 ; row-distance/count
