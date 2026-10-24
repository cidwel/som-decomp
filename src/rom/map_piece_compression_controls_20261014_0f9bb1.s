.setcpu "65816"
.segment "CODE"
.org $9BB1
map_control_0f9bb1:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
