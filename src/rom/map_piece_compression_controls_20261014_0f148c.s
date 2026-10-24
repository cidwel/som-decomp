.setcpu "65816"
.segment "CODE"
.org $148C
map_control_0f148c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
