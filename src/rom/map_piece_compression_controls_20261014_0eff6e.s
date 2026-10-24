.setcpu "65816"
.segment "CODE"
.org $FF6E
map_control_0eff6e:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
    .byte $E0 ; previous-row copy escape
    .byte $82 ; row-distance/count
