.setcpu "65816"
.segment "CODE"
.org $89C1
map_control_0c89c1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
