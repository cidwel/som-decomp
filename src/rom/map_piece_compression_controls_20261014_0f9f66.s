.setcpu "65816"
.segment "CODE"
.org $9F66
map_control_0f9f66:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
