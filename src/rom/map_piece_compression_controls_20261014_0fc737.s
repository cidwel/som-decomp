.setcpu "65816"
.segment "CODE"
.org $C737
map_control_0fc737:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
