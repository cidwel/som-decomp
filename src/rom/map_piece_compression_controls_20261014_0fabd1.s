.setcpu "65816"
.segment "CODE"
.org $ABD1
map_control_0fabd1:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
