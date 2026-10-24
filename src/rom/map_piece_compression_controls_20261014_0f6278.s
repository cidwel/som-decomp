.setcpu "65816"
.segment "CODE"
.org $6278
map_control_0f6278:
    .byte $E0 ; previous-row copy escape
    .byte $CD ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $3C ; row-distance/count
