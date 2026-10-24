.setcpu "65816"
.segment "CODE"
.org $980D
map_control_0f980d:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
