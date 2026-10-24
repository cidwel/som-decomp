.setcpu "65816"
.segment "CODE"
.org $6C75
map_control_0d6c75:
    .byte $E0 ; previous-row copy escape
    .byte $BB ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
