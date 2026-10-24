.setcpu "65816"
.segment "CODE"
.org $029E
map_control_0e029e:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
