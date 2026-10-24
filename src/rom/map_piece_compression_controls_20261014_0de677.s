.setcpu "65816"
.segment "CODE"
.org $E677
map_control_0de677:
    .byte $E0 ; previous-row copy escape
    .byte $0A ; row-distance/count
