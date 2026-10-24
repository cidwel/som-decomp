.setcpu "65816"
.segment "CODE"
.org $D320
map_control_0fd320:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
