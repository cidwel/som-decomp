.setcpu "65816"
.segment "CODE"
.org $126E
map_control_0e126e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
