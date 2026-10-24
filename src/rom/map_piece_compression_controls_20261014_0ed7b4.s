.setcpu "65816"
.segment "CODE"
.org $D7B4
map_control_0ed7b4:
    .byte $E0 ; previous-row copy escape
    .byte $48 ; row-distance/count
