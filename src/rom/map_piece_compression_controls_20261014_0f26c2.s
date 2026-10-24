.setcpu "65816"
.segment "CODE"
.org $26C2
map_control_0f26c2:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
