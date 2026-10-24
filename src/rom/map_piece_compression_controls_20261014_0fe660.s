.setcpu "65816"
.segment "CODE"
.org $E660
map_control_0fe660:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
