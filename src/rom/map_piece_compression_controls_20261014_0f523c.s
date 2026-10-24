.setcpu "65816"
.segment "CODE"
.org $523C
map_control_0f523c:
    .byte $E0 ; previous-row copy escape
    .byte $0C ; row-distance/count
