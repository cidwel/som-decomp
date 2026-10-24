.setcpu "65816"
.segment "CODE"
.org $FA70
map_control_0efa70:
    .byte $E0 ; previous-row copy escape
    .byte $2C ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $91 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $23 ; row-distance/count
