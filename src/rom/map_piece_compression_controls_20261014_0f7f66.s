.setcpu "65816"
.segment "CODE"
.org $7F66
map_control_0f7f66:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
