.setcpu "65816"
.segment "CODE"
.org $177B
map_control_0e177b:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $47 ; row-distance/count
