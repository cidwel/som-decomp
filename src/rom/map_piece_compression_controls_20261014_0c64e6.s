.setcpu "65816"
.segment "CODE"
.org $64E6
map_control_0c64e6:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
