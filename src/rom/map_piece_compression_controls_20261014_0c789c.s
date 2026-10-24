.setcpu "65816"
.segment "CODE"
.org $789C
map_control_0c789c:
    .byte $E0 ; previous-row copy escape
    .byte $12 ; row-distance/count
