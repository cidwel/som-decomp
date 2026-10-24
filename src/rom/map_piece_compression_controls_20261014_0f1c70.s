.setcpu "65816"
.segment "CODE"
.org $1C70
map_control_0f1c70:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
