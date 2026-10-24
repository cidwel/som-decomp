.setcpu "65816"
.segment "CODE"
.org $793E
map_control_0f793e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
