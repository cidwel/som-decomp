.setcpu "65816"
.segment "CODE"
.org $86C8
map_control_0c86c8:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $93 ; row-distance/count
