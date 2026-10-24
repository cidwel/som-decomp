.setcpu "65816"
.segment "CODE"
.org $8AAC
map_control_0f8aac:
    .byte $E0 ; previous-row copy escape
    .byte $99 ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $11 ; row-distance/count
