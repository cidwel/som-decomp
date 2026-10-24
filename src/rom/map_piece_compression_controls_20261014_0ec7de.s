.setcpu "65816"
.segment "CODE"
.org $C7DE
map_control_0ec7de:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
