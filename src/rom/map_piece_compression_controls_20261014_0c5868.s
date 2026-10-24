.setcpu "65816"
.segment "CODE"
.org $5868
map_control_0c5868:
    .byte $E0 ; previous-row copy escape
    .byte $0D ; row-distance/count
