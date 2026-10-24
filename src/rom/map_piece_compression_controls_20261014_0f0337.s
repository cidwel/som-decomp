.setcpu "65816"
.segment "CODE"
.org $0337
map_control_0f0337:
    .byte $E0 ; previous-row copy escape
    .byte $1C ; row-distance/count
