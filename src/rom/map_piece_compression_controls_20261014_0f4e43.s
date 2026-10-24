.setcpu "65816"
.segment "CODE"
.org $4E43
map_control_0f4e43:
    .byte $E0 ; previous-row copy escape
    .byte $08 ; row-distance/count
