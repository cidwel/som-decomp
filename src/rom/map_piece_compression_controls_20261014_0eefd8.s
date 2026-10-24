.setcpu "65816"
.segment "CODE"
.org $EFD8
map_control_0eefd8:
    .byte $E0 ; previous-row copy escape
    .byte $25 ; row-distance/count
