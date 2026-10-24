.setcpu "65816"
.segment "CODE"
.org $938E
map_control_0d938e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
