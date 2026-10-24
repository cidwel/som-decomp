.setcpu "65816"
.segment "CODE"
.org $257C
map_control_0d257c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
