.setcpu "65816"
.segment "CODE"
.org $D213
map_control_0ed213:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
