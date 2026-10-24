.setcpu "65816"
.segment "CODE"
.org $3E62
map_control_0f3e62:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
