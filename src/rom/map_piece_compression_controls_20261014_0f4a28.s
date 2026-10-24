.setcpu "65816"
.segment "CODE"
.org $4A28
map_control_0f4a28:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
