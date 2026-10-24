.setcpu "65816"
.segment "CODE"
.org $880E
map_control_0f880e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
