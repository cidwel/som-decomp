.setcpu "65816"
.segment "CODE"
.org $CF12
map_control_0dcf12:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $33 ; row-distance/count
