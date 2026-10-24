.setcpu "65816"
.segment "CODE"
.org $69F7
map_control_0f69f7:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
