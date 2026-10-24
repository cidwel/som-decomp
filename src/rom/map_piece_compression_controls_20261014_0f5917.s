.setcpu "65816"
.segment "CODE"
.org $5917
map_control_0f5917:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
