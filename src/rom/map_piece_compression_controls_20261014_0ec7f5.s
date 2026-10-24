.setcpu "65816"
.segment "CODE"
.org $C7F5
map_control_0ec7f5:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
