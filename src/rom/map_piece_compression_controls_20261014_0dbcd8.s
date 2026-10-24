.setcpu "65816"
.segment "CODE"
.org $BCD8
map_control_0dbcd8:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
