.setcpu "65816"
.segment "CODE"
.org $594E
map_control_0c594e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
