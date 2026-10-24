.setcpu "65816"
.segment "CODE"
.org $44DE
map_control_0c44de:
    .byte $E0 ; previous-row copy escape
    .byte $0B ; row-distance/count
