.setcpu "65816"
.segment "CODE"
.org $46CD
map_control_0c46cd:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
