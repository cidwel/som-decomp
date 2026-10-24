.setcpu "65816"
.segment "CODE"
.org $7A50
map_control_0f7a50:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
