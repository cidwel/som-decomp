.setcpu "65816"
.segment "CODE"
.org $26DA
map_control_0f26da:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
