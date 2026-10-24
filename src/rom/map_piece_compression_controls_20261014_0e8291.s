.setcpu "65816"
.segment "CODE"
.org $8291
map_control_0e8291:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $85 ; row-distance/count
