.setcpu "65816"
.segment "CODE"
.org $7938
map_control_0d7938:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
