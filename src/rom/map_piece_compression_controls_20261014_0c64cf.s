.setcpu "65816"
.segment "CODE"
.org $64CF
map_control_0c64cf:
    .byte $E0 ; previous-row copy escape
    .byte $0E ; row-distance/count
