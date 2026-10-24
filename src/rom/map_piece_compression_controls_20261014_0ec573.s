.setcpu "65816"
.segment "CODE"
.org $C573
map_control_0ec573:
    .byte $E0 ; previous-row copy escape
    .byte $0F ; row-distance/count
