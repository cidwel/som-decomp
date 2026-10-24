.setcpu "65816"
.segment "CODE"
.org $CA30
map_control_0dca30:
    .byte $E0 ; previous-row copy escape
    .byte $7F ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $2D ; row-distance/count
