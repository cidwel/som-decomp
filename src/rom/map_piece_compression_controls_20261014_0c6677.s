.setcpu "65816"
.segment "CODE"
.org $6677
map_control_0c6677:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
