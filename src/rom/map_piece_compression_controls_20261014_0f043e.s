.setcpu "65816"
.segment "CODE"
.org $043E
map_control_0f043e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
