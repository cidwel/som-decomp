.setcpu "65816"
.segment "CODE"
.org $354E
map_control_0e354e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
