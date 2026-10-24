.setcpu "65816"
.segment "CODE"
.org $CF8A
map_control_0dcf8a:
    .byte $E0 ; previous-row copy escape
    .byte $27 ; row-distance/count
