.setcpu "65816"
.segment "CODE"
.org $136E
map_control_0f136e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
