.setcpu "65816"
.segment "CODE"
.org $CF82
map_control_0dcf82:
    .byte $E0 ; previous-row copy escape
    .byte $35 ; row-distance/count
