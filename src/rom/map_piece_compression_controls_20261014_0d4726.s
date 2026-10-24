.setcpu "65816"
.segment "CODE"
.org $4726
map_control_0d4726:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
